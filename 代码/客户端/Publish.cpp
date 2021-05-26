#include "Publish.h"
#include "ui_Publish.h"
#include <QDateTime>
#include "MyStruct.h"
#include <QFileDialog.h>
#include <QMessageBox>
#include "QDebug"
#include <fstream>
#include <QTextCodec>
#include<QDebug>
Publish::Publish(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Publish)
{
    ui->setupUi(this);
    setWindowTitle("发布任务");
    par=parent;
}

Publish::~Publish()
{
    delete ui;
}

void transfer(char*,QString);


void Publish::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("open file"), " ",  tr("Images (*.png *.xpm *.jpg)"));
    if(fileName.isEmpty()){
        QMessageBox::warning(this,"警告","打开失败");
    } else {
        //读取文件内容
        //QFile操作默认支持的格式是utf-8
        //gtk另辟蹊径
        QTextCodec *codec=QTextCodec::codecForName("utf-8");//指定默认读取格式为gbk


        QFile file(fileName);//参数路径名称
        //指定打开方式（只读）
        file.open(QIODevice::ReadOnly);//openMode 哪种方式
        //输入输出设备中的只读
        //不管文件，磁盘，字符串统称都叫QIODevice,所有的io设备
        //可以换种方式QFIleDevice::ReadOnly
        QByteArray array;
        array=file.readAll();//一次读全部
        QFileInfo info(fileName);//读取文件信息
        //suffix()  后缀名
        qDebug()<<"路径："<<info.filePath();
        qDebug()<<"名称："<<info.fileName();
        qDebug()<<"大小："<<info.size();
        qDebug()<<"后缀名："<<info.suffix();
        qDebug()<<"创建日期："<<info.created().toString("yyyy-MM-dd HH:mm:ss");//拼接符可以是任意符号
        qDebug()<<"修改日期："<<info.lastModified().toString("yyyy MM dd HH:mm:ss");

        int len;//buf的长度
        buf = array.data();
        len = array.size();
        picSize=len;

        pic.setParent(this);
        pic.setStyleSheet("border-width: 0px;border-style: solid;border-color: rgb(211,211,211);");
        pic.show();
        pic.move(3,3);
        pic.setFixedWidth(144);
        pic.setFixedHeight(144);
        pic.setScaledContents(true);
        pic.setPixmap(QPixmap(fileName));
    }

}

void Publish::on_Publish_2_clicked()
{
    task job;
    QString content=ui->textEdit->toPlainText();
    qDebug()<<content;
    transfer(job.content,content);
    job.label=ui->comboBox->currentIndex();
    job.price=ui->doubleSpinBox->value();
    QDateTime timeCurrent = QDateTime::currentDateTime();
    QString time = timeCurrent.toString("yyyy-MM-dd hh-mm-ss");
    transfer(job.time,time);
    job.ID[0]='1';
    job.ID[1]='\0';
    job.del=0;
    job.size=picSize;
    MyClient cli;
    char ip[16]="192.168.43.182";
    cli.star(ip,1234);
    cli.Clisend(POST_TASK,job);
//    cli.command.Send(CLIENT,(char*)&buf,sizeof(job.size),0);
    qDebug()<<job.num;
}

