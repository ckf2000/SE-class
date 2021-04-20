#pragma once
#include"MySocket.h"
class MyClient
{
private:
	MySocket command;                 //命令套接字，告诉服务器即将发送消息的类型与大小，以及确认服务器的返回信息
public:
	MyClient(char* ip, u_short port, int wait_num);               //初始化客户端
	template<typename T> void Send(int type,T temp);       //发送消息，包括消息类型与消息内容
};

template<typename T>
inline void MyClient::Send(int type, T temp)
{
	cmd c;
	c.acc = false;
	c.size = sizeof(temp);
	c.type = type;
	command.Send(CLIENT,(char*)&c, sizeof(c), 0);
	command.Receive(CLIENT,(char*)& c, c.size, 0);
	if(c.acc)                                                                                //收到确认消息之后发送内容
		command.Send((char*)&temp, c.size, 0);
}
