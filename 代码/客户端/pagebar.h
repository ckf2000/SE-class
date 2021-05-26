#ifndef PAGEBAR_H
#define PAGEBAR_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QFrame>

class PageBar : public QWidget
{
    Q_OBJECT
public:
    explicit PageBar(QWidget *parent = nullptr);
    int currentpage;
    QWidget bar;
    QPushButton page[6];
    QLabel ellipsis1;
    QLabel ellipsis2;
    QPushButton turnbef;
    QPushButton turnback;
    QLabel num_page;

    void init(QWidget *parent);
    void nextpage();
    void beforepage();
    void skipto0();
    void skipto1();
    void skipto2();
    void skipto3();
    void skipto4();
    void skipto5();
signals:

};

#endif // PAGEBAR_H
