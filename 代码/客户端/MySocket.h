#ifndef MYSOCKET_H
#define MYSOCKET_H

#include<windows.h>
#include<string>
#include<iostream>
#include<WinSock.h>
#include"MyStruct.h"
#include"define.h"
using namespace std;

class MySocket                                                       //套接字封装
{
private:
    SOCKET s;
    SOCKET remote;                                                  //与远程主机连接的套接字，用于保存客户端的ip端口等信息
public:
    MySocket();
    void Bind(u_short port);                        //用于服务器绑定
    void Listen(int num);											  //用于服务器监听
    void Accept();                                                      //用于服务器等待连接
    void Receive(int c_s, char* buf, unsigned int size, int flag);        //接收消息，服务器和客户机通用
    void Send(int c_s, char* buf, unsigned int size, int flag);             //发送消息，服务器和客户机通用
    void Connect(char* ip,u_short port);                             //客户端主动连接服务器 需要服务器的ip以及端口
    void Serstart(u_short port, int wait_num);        //启动服务器套接字
};

#endif // MYSOCKET_H
