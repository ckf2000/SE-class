#include "mywindow.h"
#include "ui_mywindow.h"
#include"Personnal.h"
#include"Publish.h"
#include"Myjob.h"
#include <QFileDialog>

MyWindow::MyWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/new/prefix1/icon/logo.png"));
    //设置标题
    setWindowTitle("大学生互助系统");

    this->resize(1200,800);
    for(int i=0;i<4;i++)
    {
            sq.mb[i].fbox.setParent(this);
            connect(&sq.mb[i].title,&QPushButton::pressed,this,&QWidget::close);
            sq.mb[i].lomove(i);
    }
    sq.getparent(this);
}

MyWindow::~MyWindow()
{
    delete ui;
}

//点击按钮跳转到个人信息界面
void MyWindow::on_Personnal_clicked()
{
    Personnal* self=new Personnal(this);
    for(int i=0;i<50;i++)
    {
        self->superID[i]=superID[i];
    }
    self->Show_Info();
    self->show();

}

void MyWindow::on_Publish_clicked()
{
    Publish* publish=new Publish(this);
    for(int i=0;i<50;i++)
    {
        publish->superID[i]=superID[i];
    }
    publish->show();
}

void MyWindow::on_Myjob_clicked()
{
    Myjob* myjob=new Myjob(this);
    for(int i=0;i<50;i++)
    {
        myjob->superID[i]=superID[i];
    }
    myjob->mytask();
    myjob->show();
}
