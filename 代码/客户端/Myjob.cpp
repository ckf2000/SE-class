#include "Myjob.h"
#include "ui_Myjob.h"
#include<string>
Myjob::Myjob(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Myjob)
{
    ui->setupUi(this);
    this->resize(1200,1000);
    setWindowTitle("大学生互助系统—我的任务");
    //mytask();

}

Myjob::~Myjob()
{
    delete ui;
}
void Myjob::mytask()
{
    char ip[16]="192.168.43.182";
    MyClient myclient(ip,1234);
    sign_in s;
    for(int i=0;i<50;i++)
        s.ID[i]=superID[i];
    myclient.Clisend(MYTASK,s);
    char*pic;//接收图片
    task temp;
    int state=0;
    myclient.command.Receive(CLIENT,(char*)&state,sizeof(char),0);
    //注意这里是1
    for(int i=0;i<state;i++)
    {

        myclient.command.Receive(CLIENT,(char*)&temp,sizeof(temp),0);
//        qDebug()<<temp.size;
//        pic=new char[temp.size];
//        myclient.command.Receive(CLIENT,pic,temp.size,0);
//        string fileName=to_string(temp.num);
//        string str1="‪D:\\myphoto\\"+fileName+".jpg";
//        QString qstr = QString::fromStdString(str1);
//        qstr.replace("\u202A","");
//        string str2= qstr.toStdString();
//        qDebug()<<qstr;
//        ofstream file;
//        file.open(str2,ios::out|ios::binary);
//        if(file.is_open())
//        {
//            file.write(pic, temp.size);
//            qDebug()<<"打开成功";
//        }
//        file.close();
        mytasks.push_back(temp);
    }
    //int state;
    //注意这里是1
    //    while(1)
    //    {
    //        task temp;
    //        temp.size=0;
    //        char state=1;
    //        char*pic;//接收图片
    //        //myclient.command.Receive(CLIENT,(char*)&state,sizeof(char),0);
    //        qDebug()<<state;
    //        if(state==1)
    //        {
    //            myclient.command.Receive(CLIENT,(char*)&temp,sizeof(task),0);
    //            mytasks.push_back(temp);
    //            qDebug()<<temp.size;
    //            pic=new char[temp.size];
    //            myclient.command.Receive(CLIENT,pic,temp.size,0);
    //            string fileName = to_string(temp.num);
    //            //改成自己的路径
    //            string str1="‪D:\\myphoto\\"+fileName+".jpg";
    //            QString qstr = QString::fromStdString(str1);
    //            qstr.replace("\u202A","");
    //            string str2= qstr.toStdString();
    //            qDebug()<<qstr;
    //            ofstream file;
    //            file.open(str2,ios::out|ios::binary);
    //            if(file.is_open())
    //            {
    //                file.write(pic, temp.size);
    //                qDebug()<<"打开成功";
    //            }
    //            file.close();
    //        }
    //        else
    //        {

    //        }
    //        delete []pic;
    //    }
    for(int i=0;i<5;i++)
    {
        jobsq.mmb[i].changeui(mytasks[i]);
        jobsq.mmb[i].fbox.setParent(this);
        connect(&jobsq.mmb[i].title,&QPushButton::pressed,this,&QWidget::close);
        jobsq.mmb[i].lomove(i);
    }
}
