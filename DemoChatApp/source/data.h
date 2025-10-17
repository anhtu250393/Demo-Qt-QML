#ifndef DATA_H
#define DATA_H

#include <QObject>
#include <QThread>

#include "../DemoChatServer/source/pipeserver.h"

class Data : public QObject
{
    Q_OBJECT
    QThread workerThread;
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)

public:
    explicit Data(QObject *parent = nullptr);
    ~Data();
    QString message() const;
    void setMessage(const QString &msg);

    Q_INVOKABLE void callSendMessage(QString numberID);

signals:
    void messageChanged();

private slots:
    void runThread();

private:
    QString m_message;
    std::wstring m_pipeApp;
    HANDLE hEvent;
    std::shared_ptr<pipeServer> m_Server;

};

#endif // DATA_H
