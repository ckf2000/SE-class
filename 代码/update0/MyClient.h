#ifndef MYCLIENT_H
#define MYCLIENT_H

#include"MySocket.h"

class MyClient
{
private:
    //MySocket message;                   //消息套接字，用于发送消息
    MySocket command;                 //命令套接字，告诉服务器即将发送消息的类型与大小，以及确认服务器的返回信息
public:
    MyClient(char* ip, u_short port);
    MyClient();
    void star(char* ip, u_short port);
    template<typename T> bool Clisend(int type,T temp);
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
            //qDebug() << c.size;
            command.Send(CLIENT, (char*)&c, sizeof(c), 0);
            command.Send(CLIENT, (char*)&temp, c.size, 0);
            command.Receive(CLIENT, (char*)&c, sizeof(c), 0);
            if (c.acc)
                //登录成功
            //else
                //登录失败
            break;
        case REGISTRATION:
            //qDebug() << c.size;
            command.Send(CLIENT, (char*)&c, sizeof(c), 0);
            command.Send(CLIENT, (char*)&temp, c.size, 0);
            command.Receive(CLIENT, (char*)&c, sizeof(c), 0);
            if (c.acc)
                //注册成功
            //else
                //注册失败
            break;
        }
        return c.acc;
}


#endif // MYCLIENT_H
