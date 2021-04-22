#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"register.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


protected:
    //鼠标移动
    void mouseMoveEvent(QMouseEvent *e);
    //鼠标按下移动
    void mousePressEvent(QMouseEvent *e);


private slots:

    void on_Register_clicked();

    void on_Min_clicked();

    void on_Close_clicked();

private:
    Ui::MainWindow *ui;
    QPoint p;
};
#endif // MAINWINDOW_H
