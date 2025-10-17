#include "data.h"
#include "../DemoChatServer/source/pipeclient.h"

 #include <QDebug>

constexpr LPCWSTR pipeName = L"\\\\.\\pipe\\MyNamedPipe";

Data::Data(QObject *parent) : QObject{parent}
{
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

void Data::callSendMessage()
{
    pipeClient pipe(pipeName);
    std::string message = "";
    if(pipe.pingServer(message))
        setMessage(QString::fromStdString(message));

    qDebug() << "Message from QML:" << QString::fromStdString(message);
}
