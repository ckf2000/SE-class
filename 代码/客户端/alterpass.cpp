#include "alterpass.h"
#include "ui_alterpass.h"

Alterpass::Alterpass(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Alterpass)
{
    ui->setupUi(this);
    //去窗口边框
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    //把窗口背景设置为透明;
    setAttribute(Qt::WA_TranslucentBackground);
}

Alterpass::~Alterpass()
{
    delete ui;
}

void Alterpass::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        //求坐标差值
        //当前点击坐标-窗口左上角坐标
        p = e->globalPos() - this->frameGeometry().topLeft();
    }
}

void Alterpass::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons() & Qt::LeftButton)
    {
        //移到左上角
        move(e->globalPos() - p);
    }

}

void Alterpass::on_Close_1_clicked()
{
    this->close();
}

void Alterpass::on_Cancel_clicked()
{
    this->close();
}

void Alterpass::on_Confirm_clicked()
{
    //得到新输入的密码
    string Pass,C_pass;
    Pass=ui->Pass->text().toStdString();;
    C_pass=ui->C_pass->text().toStdString();

    //确保密码正确性（1.非空 2.两次密码一致 3.密码长度合乎规范）
    if(Pass.empty()||C_pass.empty())
    {
        QMessageBox::warning(this, "警告", "请填写全部的信息");
    }
    else if(Pass!=C_pass)
    {
        QMessageBox::warning(this, "警告", "请保证输入的两次密码的一致性。");
    }
    else if(Pass.length()<6||Pass.length()>20)
    {
        if(Pass.length()<6)
        {
            QMessageBox::warning(this, "警告", "密码的长度小于6位，请重新设置。");
        }
        else
        {
            QMessageBox::warning(this, "警告", "密码的长度大于20位，请重新设置。");
        }
    }
    else
    {
        //保证密码是英文字符和数字的组合
        bool judge0=true;//判断是否有除数字和字母外的字符
        bool judge1=false;//判断是否有数字
        bool judge2=false;//判断是否字母
        for(int i=0;i<Pass.length();i++)
        {
            if ((Pass[i] < '0' || Pass[i]>'9') && (Pass[i] < 'A' || Pass[i]>'Z') && (Pass[i] < 'a' || Pass[i]>'z'))
            {
                judge0=false;
            }
            if(Pass[i] >= '0' && Pass[i]<='9')
            {
                judge1=true;
            }
            if((Pass[i] >= 'A' && Pass[i]<='Z') || (Pass[i] >= 'a' && Pass[i]<='z'))
            {
                judge2=true;
            }
        }
        if(judge0==false||judge1==false||judge2==false)
        {
            QMessageBox::warning(this, "警告", "密码不是为英文字符和数字的组合，请重新设置。");
        }
        if(judge1==true&&judge2==true)
        {
            //把更新后的密码发送给服务器更新，并提示用户密码修改成功
            MyClient cli("192.168.43.182",1234);
            sign_in mysignin;
            for(int i=0;i<50;i++)
            {
                mysignin.ID[i]=superID[i];
            }
            for(int i=0;i<=Pass.length();i++)
            {
                mysignin.password[i]=Pass[i];
            }
            if(cli.Clisend(CHANGE_PASSWORD,mysignin))
            {
                QMessageBox::warning(this,"提示","密码修改成功");
            }
            this->close();
//            cmd c;
//            c.type=CHANGE_PASSWORD;
//            c.size=sizeof(mysignin);
//            cli.command.Send(CLIENT,(char*)&c,sizeof(c),0);
//            cli.command.Send(CLIENT,(char*)&mysignin,c.size,0);

        }
    }
}
