#include"MyClient.h"
MyClient::MyClient(char* ip, u_short port, int wait_num)
{
	command.Connect(ip, port);
}
