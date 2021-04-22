#include "register.h"
#include "ui_register.h"


Register::Register(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
    char ip[16]="192.168.43.182";
    Client.star(ip,1234);
    ui->setupUi(this);
    //去窗口边框
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    //把窗口背景设置为透明;
    setAttribute(Qt::WA_TranslucentBackground);
}

//将QString转换为char类型
void transfer(char*c,QString s)
{
    for(int i=0;i<s.size();i++)
    {
        c[i]=s[i].unicode();
    }
    c[s.size()]='\0';
}


Register::~Register()
{
    delete ui;
}


void Register::changeEvent(QEvent *event)
{
    if(event->type()!=QEvent::WindowStateChange) return;
    if(this->windowState()==Qt::WindowMinimized)
    {
       emit mysignal2();
    }
}


void Register::closeEvent(QCloseEvent *event)
{
    emit mysignal(); //发送信号
}


void Register::on_Close_1_clicked()
{
    emit mysignal();
    this->close();
}


void Register::on_Min_1_clicked()
{
    emit mysignal2();
    this->showMinimized();
}

void Register::on_Log_clicked()
{
    emit mysignal();
    this->close();
}

void Register::on_Reg_clicked()
{
    QString Sno,Name,Sex,Key,C_key,Question,Answer;
    Sno=ui->Sno->text();
    Name=ui->Name->text();
    Sex=ui->Sex->currentText();
    Key=ui->Key->text();
    C_key=ui->C_key->text();
    Question=ui->Question->text();
    Answer=ui->Answer->text();
    //在注册的健全性的保证
    //1、每一项当中都必须保证有数据在里面
    if(Sno==NULL||Name==NULL||Sex==NULL||Key==NULL||C_key==NULL||Question==NULL||Answer==NULL)
    {
        QMessageBox::warning(this, "警告", "请填写全部的信息");
    }
    //2、保证两次输入的密码是一致的
    else if(Key!=C_key)
    {
        QMessageBox::warning(this, "警告", "请保证输入的两次密码的一致性。");
    }
    //设立用户a,并将我们读取到的消息转化从字符串型
    user a;
    transfer(a.ID,Sno);
    transfer(a.nickname,Name);
    transfer(a.password,Key);
    if(Sex=="男")
    {
        a.sex[0]='0';
        a.sex[1]='\0';
    }
    else
    {
        a.sex[0]='1';
        a.sex[1]='\0';
    }
    transfer(a.question,Question);
    transfer(a.answer,Answer);
    bool judge=Client.Clisend(REGISTRATION,a);
    //在保证输入的信息没有误的情况下看是否注册成功
       if(Sno!=NULL&&Name!=NULL&&Sex!=NULL&&Key!=NULL&&C_key!=NULL&&Question!=NULL&&Answer!=NULL&&Key==C_key)
       {
           if(judge==true)
           {
               QMessageBox::information(this, "提示", "注册成功，请点击登录返回登陆界面。");
           }
           else
           {
               QMessageBox::information(this, "提示", "注册失败，该账户已经存在，请重新输入信息。");
           }
       }
}

