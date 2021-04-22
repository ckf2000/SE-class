#ifndef REGISTER_H
#define REGISTER_H

#include <QMainWindow>
#include"MyClient.h"
#include<qmessagebox.h>


namespace Ui {
class Register;
}

class Register : public QMainWindow
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

signals:
    //关闭信号
    void mysignal();
    //最小化信号
    void mysignal2();

protected:
    //最小化事件
    void changeEvent(QEvent * event);
    //关闭事件
    virtual void closeEvent(QCloseEvent *event);

private slots:

    void on_Close_1_clicked();

    void on_Min_1_clicked();

    void on_Log_clicked();

    void on_Reg_clicked();

private:
    Ui::Register *ui;
    MyClient Client;

};

#endif // REGISTER_H
