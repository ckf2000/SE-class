#include "Personnal.h"
#include "ui_Personnal.h"

void transfer(char*,QString);

Personnal::Personnal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Personnal)
{
    ui->setupUi(this);
    //去窗口边框
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    //把窗口背景设置为透明;
    setAttribute(Qt::WA_TranslucentBackground);


}

Personnal::~Personnal()
{
    delete ui;
}

void Personnal::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        //求坐标差值
        //当前点击坐标-窗口左上角坐标
        p = e->globalPos() - this->frameGeometry().topLeft();
    }
}

void Personnal::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons() & Qt::LeftButton)
    {
        //移到左上角
        move(e->globalPos() - p);
    }

}

void Personnal::on_Min_1_clicked()
{
    this->showMinimized();
}

void Personnal::on_Close_1_clicked()
{
    this->close();
}

void Personnal::on_AlterInfo_clicked()
{
    //得到更改后的个人信息
    QString Name,Sex;
    Name=ui->Name->text();
    Sex=ui->Sex->text();

    //保证修改后的信息合乎规范（1.昵称字符规范；2.性别只能为“男”或“女”
    //code there!
    if(Name==NULL)
    {
        QMessageBox::warning(this, "警告", "昵称不能为空。");
    }
    if(!(Sex=="男"||Sex=="女"))
    {
        QMessageBox::warning(this, "警告", "性别请填写‘男’或‘女’。");
    }
    else
    {
        //把修改后的信息发给服务器更新,并提示用户更新成功
        //code there!
        MyClient cli("192.168.43.182",1234);
        user u;
        for(int i=0;i<50;i++)
        {
            u.ID[i]=superID[i];
        }
        transfer(u.nickname,Name);
        if(Sex=="男")
        {
            u.sex[0]='0';
            u.sex[1]='\0';
        }
        else if(Sex=="女")
        {
            u.sex[0]='1';
            u.sex[1]='\0';
        }
        if(cli.Clisend(CHANGE_INFORMATION,u))
        {
            QMessageBox::information(this, "提示", "信息修改成功");
        }

    }
}

void Personnal::on_Alterpass_clicked()
{
    Alterpass* ap=new Alterpass(this);
    for(int i=0;i<50;i++)
    {
     ap->superID[i]=superID[i];
    }
    ap->show();
}


void Personnal::Show_Info()
{
    QString sex;
    ui->Sno->setText(superID);
    MyClient client("192.168.43.182",1234);
    user u;
    for(int i=0;i<50;i++)
    {
       u.ID[i]=superID[i];
    }
    client.Clisend(SEARCH_INFORMATION,u);
    client.command.Receive(CLIENT,(char*)&u,sizeof(u),0);
    ui->Name->setText(u.nickname);
    if(u.sex[0]==1) sex="女";
    else sex="男";
    ui->Sex->setText(sex);
    ui->Question->setText(u.question);
    ui->Answer->setText(u.answer);

    //锁定学号、验证问题、问题答案，不允许修改
    ui->Sno->setReadOnly(true);
    ui->Question->setReadOnly(true);
    ui->Answer->setReadOnly(true);
}
