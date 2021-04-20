#pragma once
#include<iostream>
using namespace std;
struct user
{
	string ID;
	string password;
	string question;
	string answer;
	string nickname;
	string sex;
};

struct sign_in
{
	string ID;
	string password;
};

struct change_password
{
	string ID;
	string old_p;
	string new_p;
};

struct cmd
{
	int type=-1;
	unsigned int size;
	bool acc;
};