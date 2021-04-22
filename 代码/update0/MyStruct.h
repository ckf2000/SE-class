#ifndef MYSTRUCT_H
#define MYSTRUCT_H

#include<iostream>
using namespace std;
struct user
{
    char ID[50];
    char password[50];
    char question[50];
    char answer[50];
    char nickname[50];
    char sex[50];
};

struct sign_in
{
    char ID[50];
    char password[50];
};

struct change_password
{
    char ID[50];
    char old_p[50];
    char new_p[50];
};

struct cmd
{
    int type=-1;
    unsigned int size;
    bool acc;
};

#endif // MYSTRUCT_H
