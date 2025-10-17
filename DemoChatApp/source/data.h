#ifndef DATA_H
#define DATA_H

#include <QObject>

class Data : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)

public:
    explicit Data(QObject *parent = nullptr);
    QString message() const;
    void setMessage(const QString &msg);

    Q_INVOKABLE void callSendMessage();

signals:
    void messageChanged();

private:
    QString m_message;
signals:
};

#endif // DATA_H
