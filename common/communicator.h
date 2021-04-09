#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

#include <QUdpSocket>
#include <QObject>

struct CommParams
{
    QHostAddress rHost;
    quint16      rPort;
    QHostAddress sHost;
    quint16      sPort;
};

class Communicator : public QUdpSocket
{
    Q_OBJECT

    bool ready;
    CommParams params;
public:
    Communicator(CommParams&);

signals:
    void recieved(QByteArray);

public slots:
    void send(QByteArray);

private slots:
    void recieve();

};

#endif // COMMUNICATOR_H
