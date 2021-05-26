#include"MySocket.h"
#include<QDebug>
MySocket::MySocket()
{
    WSADATA wsadata;
    WSAStartup(MAKEWORD(2, 2), &wsadata);
    s = socket(AF_INET, SOCK_STREAM, 0);
    remote = socket(AF_INET, SOCK_STREAM, 0);
    if (SOCKET_ERROR == s) {
        qDebug()<<"套接字闯创建失败!";
    }
    else {
        qDebug()<<"套接字创建成功!" ;
    }
}

void MySocket::Bind(u_short port)
{
    sockaddr_in socketAddr;  //一个绑定地址:有IP地址,有端口号,有协议族
    socketAddr.sin_family = AF_INET;
    socketAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    socketAddr.sin_port = htons(port);
    int bRes = bind(s, (SOCKADDR*)&socketAddr, sizeof(SOCKADDR));	//绑定注意的一点就是记得强制类型转换
    if (SOCKET_ERROR == bRes) {
        qDebug()<<"绑定失败!";
    }
    else {
        qDebug()<<"绑定成功!" ;
    }
}

void MySocket::Listen(int num)
{
    int lLen = listen(s, num);	//监听的第二个参数就是:能存放多少个客户端请求,到并发编程的时候很有用哦
    if (SOCKET_ERROR == lLen) {
        qDebug()<<"监听失败!" ;
    }
    else {
        qDebug()<<"监听成功!" ;
    }
}

void MySocket::Accept()
{
    sockaddr_in revClientAddr;
    remote = INVALID_SOCKET;	//初始化一个接受的客户端socket
    int _revSize = sizeof(sockaddr_in);
    remote = accept(s, (SOCKADDR*)&revClientAddr, &_revSize);
    if (INVALID_SOCKET == remote) {
        qDebug()<<"服务端接受请求失败!" ;
    }
    else {
        qDebug()<<"服务端接受请求成功!" ;
    }
}

void MySocket::Receive(int c_s, char* buf, unsigned int size, int flag)
{
    if (c_s == CLIENT)
        remote = s;
    int reLen = recv(remote, buf, size, flag);
    if (SOCKET_ERROR == reLen) {
        qDebug()<<"服务端接收数据失败!" ;
    }
    else {
        qDebug()<<"服务器接受到数据:" ;
    }
}

void MySocket::Send(int c_s, char* buf, unsigned int size, int flag)
{
    if (c_s == CLIENT)
        remote = s;
    int sLen = send(remote, buf, size, flag);
    if (SOCKET_ERROR == sLen) {
        qDebug()<<"发送数据失败" ;
    }
    else {
        qDebug()<<"已经发送到数据:" ;
    }
}
void MySocket::Connect(char* ip, u_short port)
{
    sockaddr_in addrSrv;
    s = socket(AF_INET, SOCK_STREAM, 0);
    addrSrv.sin_addr.S_un.S_addr = inet_addr(ip);
    addrSrv.sin_family = AF_INET;
    addrSrv.sin_port = htons(port);
   int a= connect(s, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
   if (SOCKET_ERROR == a) {
       qDebug()<<"conntect123" ;
   }
   else {
       qDebug()<<"conntct成功:" ;
   }
}

void MySocket::Serstart(u_short port, int wait_num)
{
    Bind(port);
    Listen(wait_num);
    Accept();
}
