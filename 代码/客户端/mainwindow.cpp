#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"MyStruct.h"
#include"MyClient.h"
#include"Forget.h"
#include"register.h"
#include <QMouseEvent>
#include <QPainter>
#include<qmessagebox.h>
#include <QSettings>
#include<QLabel>
#include<QString>
#include<QDebug>
#include<QTextBrowser>

void transfer(char*,QString);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //去窗口边框
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    //把窗口背景设置为透明;
    setAttribute(Qt::WA_TranslucentBackground);
    QMessageBox::information(this, "提示", "密码的长度大于20位，请重新设置。");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        //求坐标差值
        //当前点击坐标-窗口左上角坐标
        p = e->globalPos() - this->frameGeometry().topLeft();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons() & Qt::LeftButton)
    {
        //移到左上角
        move(e->globalPos() - p);
    }

}

//点击跳转到注册页面
void MainWindow::on_Register_clicked()
{
    Register *rw=new Register(this);
    rw->show();
    rw->resize(920,1000);
    rw->move ((QApplication::desktop()->width() - rw->width())/2,(QApplication::desktop()->height() - rw->height())/2);
    //收到第二个窗口关闭信号显示第一窗口
    connect(rw,SIGNAL(mysignal()),this,SLOT(my_show_slot()));
    //将子窗口的最小化与父窗口的最小化关联
    connect(rw,SIGNAL(mysignal2()),this,SLOT(on_Min_clicked()));
    //隐藏第一个界面
    this->hide();

}

void MainWindow::my_show_slot()
{
    this->show();
}

//关闭窗口
void MainWindow::on_Close_clicked()
{
    close();
}

//窗口最小化
void MainWindow::on_Min_clicked()
{
    showMinimized();
}

//登录
void MainWindow::on_Login_clicked()
{
    QString id_=ui->Username->text();
    QString password_=ui->Password->text();
    sign_in mysignin;
    transfer(mysignin.ID,id_);
    transfer(mysignin.password,password_);

    char ip[16]="192.168.43.182";
    MyClient myclient(ip,1234);
    bool sign_or_not =myclient.Clisend(0,mysignin);
    if(sign_or_not)
    {
        close();
        MyWindow *rw=new MyWindow(this);
        for(int i=0;i<50;i++)
        {
            rw->superID[i]=mysignin.ID[i];
        }
        rw->show();
    }
    else
    {
        QMessageBox::warning(this, "警告", "账号密码不匹配!!");
    }
}

//忘记密码
void MainWindow::on_Forget_clicked()
{
    Forget* forget=new Forget(this);
    forget->show();
    forget->resize(400,150);
    forget->move ((QApplication::desktop()->width() - forget->width())/2,(QApplication::desktop()->height() - forget->height())/2);
    //设置窗口的图标以及窗口的名字
    forget->setWindowIcon(QIcon(":/new/prefix1/icon/logo.png"));
    forget->setWindowTitle("忘记密码");
    //建立一个提示消息
    QLabel* text1=new QLabel(forget);
    text1->setGeometry(0,0,200,30);
    text1->setText("请输入你的学号");
    text1->setFont(QFont("Timers", 15, QFont::Bold));
    text1->show();
    //建立一个文本框读取账号
    QLineEdit* in=new QLineEdit(forget);
    in->setGeometry(0,40,400,50);
    in->show();
    //建立一个确认按钮
    QPushButton* confirm=new QPushButton(forget);
    confirm->resize(60,40);
    confirm->setGeometry(140,90,120,60);
    confirm->setText("确认");
    confirm->show();
    connect(confirm,&QPushButton::clicked,forget,[=]()
    {
        //将文本读取出来
        QString account;
        account=in->text();
        //输入的为空值时
        if(account==NULL)
        {
            QMessageBox::information(this, "提示", "该选项不能为空，请输入你的账号.");
        }
        else
        {
            //创建套接字，连接服务器端
            MyClient Client;
            char ip[16]="192.168.43.182";
            Client.star(ip,1234);
            user F;
            //将QString转换为char类型
            for(int i=0;i<account.size();i++)
            {
                F.ID[i]=account[i].unicode();
            }
            F.ID[account.size()]='\0';
            //给服务器发送和接收到消息，这里里面没有对应的账户的情况没有进行考虑，后续需要优化
            cmd c;
            c.size=sizeof(F.ID);
            c.type=FORGET;
            Client.command.Send(CLIENT,(char*)&c,sizeof(c),0);
            Client.command.Send(CLIENT,F.ID,sizeof(F.ID),0);
            Client.command.Receive(CLIENT,(char*)&F,sizeof(F),0);

            //关闭原界面，打开回答验证问题的界面
            forget->close();
            Forget* question=new Forget(this);
            question->show();
            question->resize(500,550);
            question->move ((QApplication::desktop()->width() - question->width())/2,(QApplication::desktop()->height() - question->height())/2);
            //设置窗口的图标以及窗口的名字
            question->setWindowIcon(QIcon(":/new/prefix1/icon/logo.png"));
            question->setWindowTitle("验证问题页面");
            QLabel* text2=new QLabel(question);
            text2->setGeometry(0,0,500,50);
            text2->setText("验证问题：");
            text2->setFont(QFont("Timers", 15, QFont::Bold));
            text2->show();
            QLabel* text3=new QLabel(question);
            text3->setGeometry(0,250,500,50);
            text3->setText("请输入你的验证问题的答案后点击确认");
            text3->setFont(QFont("Timers", 15, QFont::Bold));
            text3->show();
            //利用一个控件来加载验证问题
            QTextBrowser* showtext=new QTextBrowser(question);
            showtext->setFontPointSize(18);
            QString str(F.question);
            showtext->setText("我的验证问题是："+str);
            showtext->setGeometry(0,50,500,200);
            showtext->show();
            //建立一个文本框读取验证问题的答案
            QTextEdit* answer=new QTextEdit(question);
            answer->setFontPointSize(18);
            answer->setFont(QFont("Timers", 15, QFont::Bold));
            answer->setGeometry(0,300,500,200);
            answer->show();


            //建立一个确认按钮
            QPushButton* confirm=new QPushButton(question);
            confirm->resize(60,40);
            confirm->setGeometry(0,500,500,50);
            confirm->setText("确认");
            confirm->show();

            //根据问题是否回答正确来进行密码的修改
            connect(confirm,&QPushButton::clicked,question,[=]()
            {
                QString ques_ans;
                ques_ans=answer->toPlainText();
                char temp[50];
                for(int i=0;i<ques_ans.size();i++)
                {
                    temp[i]=ques_ans[i].unicode();
                }
                temp[ques_ans.size()]='\0';
                bool isright=false;
                for(int i=0;i<=ques_ans.size();i++)
                {
                    if(temp[i]==F.answer[i])
                    {
                        isright=true;
                    }
                }
                if(isright==true)
                {
                    question->close();
                    Forget* change=new Forget(this);
                    change->show();
                    change->resize(500,200);
                    change->move ((QApplication::desktop()->width() - change->width())/2,(QApplication::desktop()->height() - change->height())/2);
                    //设置窗口的图标以及窗口的名字
                    change->setWindowIcon(QIcon(":/new/prefix1/icon/logo.png"));
                    change->setWindowTitle("重置密码");
                    //建立一个提示消息
                    QLabel* text4=new QLabel(change);
                    text4->setGeometry(0,0,300,30);
                    text4->setText("请输入你的密码并确认");
                    text4->setFont(QFont("Timers", 15, QFont::Bold));
                    text4->show();
                    //利用两个QLabel来加载提示
                    QLabel* text5=new QLabel(change);
                    QLabel* text6=new QLabel(change);
                    text5->setGeometry(0,40,110,50);
                    text6->setGeometry(0,90,110,50);
                    text5->setText(" 新密码 ");
                    text6->setText("确认新密码");
                    text5->setFont(QFont("Timers", 12, QFont::Bold));
                    text5->show();
                    text6->setFont(QFont("Timers", 12, QFont::Bold));
                    text6->show();
                    //建立两个个文本框来设置密码
                    QLineEdit* key1=new QLineEdit(change);
                    key1->setGeometry(110,40,350,50);
                    key1->show();
                    QLineEdit* key2=new QLineEdit(change);
                    key2->setGeometry(110,90,350,50);
                    key2->show();
                    //建立一个确认按钮
                    QPushButton* confirm=new QPushButton(change);
                    confirm->resize(60,40);
                    confirm->setGeometry(220,140,120,60);
                    confirm->setText("确认");
                    confirm->show();
                    //设置密码之后点击确认按钮进行修改
                    connect(confirm,&QPushButton::clicked,change,[=]()
                    {
                        //读取设置的密码
                        QString str0,str1;
                        str0=key1->text();
                        str1=key2->text();
                        //保证输入的密码不为空
                        if(str0==NULL||str1==NULL)
                        {
                            QMessageBox::warning(this, "警告", "请填写全部的信息。");
                        }
                        //保证两次输入的密码是相同的
                        else if(str0!=str1)
                        {
                            QMessageBox::warning(this, "警告", "请确认两次输入的密码是一致的。");
                        }
                        //保证密码的长度是在6-20位
                        else if(str0.length()<6||str0.length()>20)
                        {
                            if(str0.length()<6)
                            {
                                QMessageBox::warning(this, "警告", "密码的长度小于6位，请重新设置。");
                            }
                            else
                            {
                                QMessageBox::warning(this, "警告", "密码的长度大于20位，请重新设置。");
                            }
                        }

                        //保证密码是英文字符和数字的组合
                        bool judge0=true;//判断是否有除数字和字母外的字符
                        bool judge1=false;//判断是否有数字
                        bool judge2=false;//判断是否字母
                        for(int i=0;i<str0.length();i++)
                        {
                            if ((str0[i] < '0' || str0[i]>'9') && (str0[i] < 'A' || str0[i]>'Z') && (str0[i] < 'a' || str0[i]>'z'))
                            {
                                judge0=false;
                            }
                            if(str0[i] >= '0' && str0[i]<='9')
                            {
                                judge1=true;
                            }
                            if((str0[i] >= 'A' && str0[i]<='Z') || (str0[i] >= 'a' && str0[i]<='z'))
                            {
                                judge2=true;
                            }
                        }
                        if(judge0==false||judge1==false||judge2==false)
                        {
                            QMessageBox::warning(this, "警告", "密码不是为英文字符和数字的组合，请重新设置。");
                        }
                        else if(judge1==true&&judge2==true)
                        {
                            sign_in change_key;
                            //进行id的初始化
                            for(int i=0;i<50;i++)
                            {
                                change_key.ID[i]=F.ID[i];
                            }
                            //将密码转化成char
                            for(int i=0;i<str0.size();i++)
                            {
                                change_key.password[i]=str0[i].unicode();
                            }
                            change_key.password[str0.size()]='\0';
                            MyClient Client;
                            char ip[16]="192.168.43.182";
                            Client.star(ip,1234);
                            bool change_or_not=Client.Clisend(CHANGE_PASSWORD,change_key);
                            if(change_or_not)
                            {
                                QMessageBox::information(this, "提示", "重设密码成功,请关闭当前窗口后返回登录界面进行登录。");
                                change->close();
                            }
                            else
                            {
                                QMessageBox::information(this, "提示", "重设密码失败。");
                            }
                        }
                    });
                }
                else
                {
                    QMessageBox::information(this, "提示", "验证问题回答错误,请重新输入答案。");
                }
            });


        }
    });

}
