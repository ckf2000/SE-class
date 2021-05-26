#ifndef PERSONNAL_H
#define PERSONNAL_H

#include "alterpass.h"
#include"define.h"
#include <QMainWindow>
#include <QMouseEvent>

namespace Ui {
class Personnal;
}

class Personnal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Personnal(QWidget *parent = 0);
    ~Personnal();
    char superID[50];

    //显示个人信息
    void Show_Info();

protected:
    //鼠标移动
    void mouseMoveEvent(QMouseEvent *e);
    //鼠标按下移动
    void mousePressEvent(QMouseEvent *e);

private slots:
    void on_Min_1_clicked();

    void on_Close_1_clicked();

    void on_AlterInfo_clicked();

    void on_Alterpass_clicked();

private:
    Ui::Personnal *ui;
    QPoint p;
};

#endif // PERSONNAL_H
