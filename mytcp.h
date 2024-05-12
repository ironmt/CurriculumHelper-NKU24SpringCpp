#ifndef MYTCP_H
#define MYTCP_H

#include <QWidget>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class MyTcp : public QObject
{
    Q_OBJECT
public:
    MyTcp(QObject *parent = nullptr);
    ~MyTcp();

    void update_cochalot(const QString &text);

private:
    //初始化server
    void init_server();
    //close
    void close_server();

signals:
    void recv_chatgpt(const QString &text);

public slots:
    void send_to_gpt(const QString &text);

private:
    QTcpServer *server;
    QList<QTcpSocket*> client_list;
};

#endif // MYTCP_H
