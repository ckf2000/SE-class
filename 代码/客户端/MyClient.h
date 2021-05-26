#ifndef MYCLIENT_H
#define MYCLIENT_H
#include<QDebug>
#include"MySocket.h"
class MyClient
{
public:
    MyClient(char* ip, u_short port);
    MyClient();
    void star(char* ip, u_short port);
    template<typename T> bool Clisend(int type,T temp);
    MySocket command;                 //命令套接字，告诉服务器即将发送消息的类型与大小，以及确认服务器的返回信息
};

template<typename T>
inline bool MyClient::Clisend(int type, T temp)
{
    cmd c;
    c.acc = false;
    c.size = sizeof(temp);
    c.type = type;
    switch (type)
    {
    case SIGN_IN:
        qDebug() << c.size;
        command.Send(CLIENT, (char*)&c, sizeof(c), 0);
        command.Send(CLIENT, (char*)&temp, c.size, 0);
        command.Receive(CLIENT, (char*)&c, sizeof(c), 0);
        break;
    case REGISTRATION:
        qDebug() << c.size;
        command.Send(CLIENT, (char*)&c, sizeof(c), 0);
        command.Send(CLIENT, (char*)&temp, c.size, 0);
        command.Receive(CLIENT, (char*)&c, sizeof(c), 0);
        break;
    case CHANGE_PASSWORD:
        qDebug() << c.size;
        command.Send(CLIENT, (char*)&c, sizeof(c), 0);
        command.Send(CLIENT, (char*)&temp, c.size, 0);
        command.Receive(CLIENT, (char*)&c, sizeof(c), 0);
        break;
    case CHANGE_INFORMATION:
        command.Send(CLIENT, (char*)&c, sizeof(c), 0);
        command.Send(CLIENT, (char*)&temp, c.size, 0);
        command.Receive(CLIENT, (char*)&c, sizeof(c), 0);
        break;
    case POST_TASK:
        command.Send(CLIENT, (char*)&c, sizeof(c), 0);
        command.Send(CLIENT, (char*)&temp, c.size, 0);
        command.Receive(CLIENT, (char*)&c, sizeof(c), 0);
        break;
    case SEARCH_INFORMATION:
        command.Send(CLIENT, (char*)&c, sizeof(c), 0);
        command.Send(CLIENT, (char*)&temp, c.size, 0);
        command.Receive(CLIENT, (char*)&c, sizeof(c), 0);
        break;
    case MYTASK:
        command.Send(CLIENT, (char*)&c, sizeof(c), 0);
        command.Send(CLIENT, (char*)&temp, c.size, 0);
        //command.Receive(CLIENT, (char*)&c, sizeof(c), 0);
        break;
    }
    return c.acc;

}
#endif // MYCLIERT_
