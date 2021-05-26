#ifndef PUBLISH_H
#define PUBLISH_H

#include <QMainWindow>
#include <QLabel>
#include<MyClient.h>
namespace Ui {
class Publish;
}

class Publish : public QMainWindow
{
    Q_OBJECT

public:
    explicit Publish(QWidget *parent = 0);
    ~Publish();
    char superID[50];

private slots:
    void on_pushButton_clicked();

    void on_Publish_2_clicked();

private:
    Ui::Publish *ui;
    QWidget *par;
    QLabel pic;
    int picSize;
    char *buf;//只是一个指针
};

#endif // PUBLISH_H
