#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"MyStruct.h"
#include"MyClient.h"
#include <QMouseEvent>
#include <QPainter>
#include<qmessagebox.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //去窗口边框
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    //把窗口背景设置为透明;
    setAttribute(Qt::WA_TranslucentBackground);
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

void MainWindow::on_Close_clicked()
{
    close();
}


void MainWindow::on_Min_clicked()
{
    showMinimized();
}


void MainWindow::on_Login_clicked()
{
    string id_=ui->Username->text().toStdString();
    string password_=ui->Password->text().toStdString();
    sign_in mysignin;
    for(int i=0;i<id_.length();i++)
    {
        mysignin.ID[i]=id_[i];
    }
    for(int i=0;i<password_.length();i++)
    {
        mysignin.password[i]=password_[i];
    }
    char ip[16]="192.168.43.182";
    MyClient myclient(ip,1234);
    myclient.Clisend(0,mysignin);
    if(true)
    {
        close();
        MyWindow *mw=new MyWindow(this);
        mw->show();
    }
    else
    {
        QMessageBox::warning(this, "警告", "账号密码不匹配!!");
    }

}

