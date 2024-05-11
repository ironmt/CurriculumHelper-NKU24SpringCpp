#include "mytcp.h"
// #include <QTcpServer>
#include <QHostAddress>
#include "mainwindow.h"

MyTcp::MyTcp(QObject *parent) : QObject(parent)
{
    init_server();
}

MyTcp::~MyTcp()
{
    close_server();
}

void MyTcp::update_cochalot(const QString &text)
{
    emit recv_chatgpt(text);
}

void MyTcp::init_server()
{
    //创建server
    server = new QTcpServer(this);

    const QString address_text = "127.0.0.1";
    const QHostAddress address_=(address_text == "Any") ? QHostAddress::Any: QHostAddress(address_text);
    const unsigned short port = 23333;

    update_state();

    connect(server, &QTcpServer::newConnection, this, [this]{
        while (server->hasPendingConnections())
        {
            QTcpSocket *socket = server->nextPendingConnection();
            client_list.append(socket);

            connect(socket, &QTcpSocket::readyRead, [this, socket]{
                if (socket->bytesAvailable() <= 0)
                    return ;
                const QString recv_text = QString::fromUtf8(socket->readAll());
                MainWindow *mw = new MainWindow;
                connect(server, &MyTcp::recv_chatgpt, mw, &MainWindow::update_note);
                update_cochalot(recv_text);
            });
        }
    });
}


