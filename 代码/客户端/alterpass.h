#ifndef ALTERPASS_H
#define ALTERPASS_H

#include <QMainWindow>
#include <QMouseEvent>
#include<qmessagebox.h>
#include"MyClient.h"

namespace Ui {
class Alterpass;
}

class Alterpass : public QMainWindow
{
    Q_OBJECT

public:
    explicit Alterpass(QWidget *parent = 0);
    ~Alterpass();
    char superID[50];

protected:
    //鼠标移动
    void mouseMoveEvent(QMouseEvent *e);
    //鼠标按下移动
    void mousePressEvent(QMouseEvent *e);

private slots:
    void on_Close_1_clicked();

    void on_Confirm_clicked();

    void on_Cancel_clicked();

private:
    Ui::Alterpass *ui;
    QPoint p;
};

#endif // ALTERPASS_H
