#include "mytcp.h"
// #include <QTcpServer>
#include <QHostAddress>

MyTcp::MyTcp(QObject *parent) : QObject(parent)
{
    init_server();
}

MyTcp::~MyTcp()
{
    close_server();
}

//发送信号给mainwindow，收到了gpt的回复
void MyTcp::update_cochalot(const QString &text)
{
    emit recv_chatgpt(text);
}

//槽函数，把问题发给gpt
void MyTcp::send_to_gpt(const QString &text)
{
    if(!server->isListening())
        return ;
    //将发送区文本发送给客户端
    const QByteArray send_data=text.toUtf8();

    //数据为空就返回
    if(send_data.isEmpty())
        return;
    for(QTcpSocket *socket:qAsConst(client_list))
    {
        socket->write(send_data);
        //socket->waitForBytesWritten();
    }
}

void MyTcp::init_server()
{
    //创建server
    server = new QTcpServer(this);

    const QString address_text = "Any";//"127.0.0.1";
    const QHostAddress address_=(address_text == "Any") ? QHostAddress::Any: QHostAddress(address_text);
    const unsigned short port = 9000;

    //判断是否连接成功
    if (server->listen(address_, port))
        qDebug() << "connection constructed!";

    connect(server, &QTcpServer::newConnection, this, [this]{
        while (server->hasPendingConnections())
        {
            QTcpSocket *socket = server->nextPendingConnection();
            client_list.append(socket);

            qDebug() << "New connection!";

            //收到数据，用update_cochalot发送信号，在mainwindow中设计槽，更新界面上的文本，把chatgpt回传的recv_text显示在窗口
            connect(socket, &QTcpSocket::readyRead, [this, socket]{
                if (socket->bytesAvailable() <= 0)
                    return ;
                const QString recv_text = QString::fromUtf8(socket->readAll());
                qDebug() << "Read:" << recv_text;
                update_cochalot(recv_text);
            });

            //如果出现错误，显示错误信息
            connect(socket,&QAbstractSocket::errorOccurred,[this,socket](QAbstractSocket::SocketError){
                qDebug() << (QString("[%1:%2] Soket Error:%3")
                                 .arg(socket->peerAddress().toString())
                                 .arg(socket->peerPort())
                                 .arg(socket->errorString()));
            });

            //client断开连接时，销毁socket
            connect(socket,&QTcpSocket::disconnected,[this,socket]{
                socket->deleteLater();
                client_list.removeOne(socket);
                qDebug() << (QString("[%1:%2] Soket Disonnected")
                                         .arg(socket->peerAddress().toString())
                                         .arg(socket->peerPort()));
            });


        }
    });

    //server错误，发出信息
    connect(server,&QTcpServer::acceptError,[this](QAbstractSocket::SocketError){
        qDebug() << ("Server Error:"+server->errorString());
    });
}

void MyTcp::close_server()
{
    //停止服务
    server->close();
    for(QTcpSocket * socket:qAsConst(client_list))
    {
        //断开与客户端的连接
        socket->disconnectFromHost();
        if(socket->state()!=QAbstractSocket::UnconnectedState){
            socket->abort();
        }
    }
}




