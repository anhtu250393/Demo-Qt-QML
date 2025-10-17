#include "data.h"
#include "../DemoChatServer/source/pipeclient.h"

 #include <QDebug>

constexpr LPCWSTR pipeName = L"\\\\.\\pipe\\MyNamedPipe";

Data::Data(QObject *parent): QObject{parent}
{
    hEvent = CreateEvent( NULL, TRUE, FALSE, NULL);
}

Data::~Data()
{
    workerThread.exit();
}

QString Data::message() const
{
    return m_message;
}

void Data::setMessage(const QString &msg)
{
    if(m_message == msg)
        return;

    m_message = msg;
    emit messageChanged();
}

void Data::callSendMessage(QString numberID)
{
    pipeClient client(pipeName);
    std::string strNumberID = numberID.toStdString();

    m_pipeApp = pipeName + numberID.toStdWString();

    moveToThread(&workerThread);
    connect(&workerThread, SIGNAL(started()), this, SLOT(runThread()));
    workerThread.start();

    QThread::msleep(1000);

    if(client.pingServer(strNumberID))
        return;

    DWORD dwWait = WaitForSingleObject(hEvent, INFINITE);
    qDebug() << "event: " << m_pipeApp;
    setMessage(QString::fromStdString("aaa"));
}

void Data::runThread()
{
    m_Server = std::make_shared<pipeServer>(m_pipeApp.c_str());
    if(m_Server->create())
        m_Server->waitPipeEvent(hEvent);
}
