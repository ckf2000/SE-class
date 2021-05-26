#ifndef MY_MESS_BOX_H
#define MY_MESS_BOX_H
#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include<string>
#include"MyStruct.h"
#include"MyClient.h"

class My_Mess_Box : public QWidget
{
    Q_OBJECT
public:
    explicit My_Mess_Box(QWidget *parent = nullptr);
    QWidget fbox;
    QLabel pic;
    QPushButton title;
    QLabel content;
    QLabel price;
    QLabel label;

    QPushButton delete_;
    QLabel time;
    char superID[50];
    void lomove(int num);
    void readjob();
    void deletemyWight();//删除任务
    void changeui(task mytask);
signals:

};
#endif // MY_MESS_BOX_H
