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

struct task
{
    char ID[50];//用户ID
    char content[400];//内容
    double price;//价格
    int label;// 标签
    char time[20];//时间 格式待定
    int num;//任务编号（客户端新建任务时不填，保存在服务器）
    int del=0;// 是否被删除，0未删除，1已经删除
    int size;//图片大小
};

#endif // MYSTRUCT_H
