#include"MyClient.h"

MyClient::MyClient(char*ip, u_short port)
{
    //message.Connect(ip, port);
    command.Connect(ip, port);
}

void MyClient::star(char* ip, u_short port)
{
    command.Connect(ip, port);
}

MyClient::MyClient()
{

}

