#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QVector>

class server : public QObject
{
    Q_OBJECT
public:
    explicit server(QObject *parent = nullptr);
    void startServer();
    void sendMessageToClients(QString message);

public slots:
    void newClientConnection();
    void socketDisconnected();
    void socketReadyRead();
    void socketStateChanged(QAbstractSocket::SocketState state);

signals:

private:
    QTcpServer* chatServer;
    QVector<QTcpSocket*>* allClients;
};

#endif // SERVER_H
