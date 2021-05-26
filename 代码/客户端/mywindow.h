#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>
#include "square.h"

namespace Ui {
class MyWindow;
}

class MyWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyWindow(QWidget *parent = nullptr);
    ~MyWindow();
    char superID[50];

private slots:
    void on_Personnal_clicked();

    void on_Publish_clicked();

    void on_Myjob_clicked();

private:
    Ui::MyWindow *ui;
    Square sq;
};

#endif // MYWINDOW_H
