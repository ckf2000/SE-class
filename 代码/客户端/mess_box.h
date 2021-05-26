#ifndef MESS_BOX_H
#define MESS_BOX_H

#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QPushButton>

class Mess_Box : public QWidget
{
    Q_OBJECT
public:
    explicit Mess_Box(QWidget *parent = nullptr);
    QWidget fbox;
    QLabel pic;
    QPushButton title;
    QLabel content;
    QLabel price;
    QLabel label;

    QPushButton rec;
    QLabel time;

    void lomove(int num);
    void readjob();
signals:

};

#endif // MESS_BOX_H
