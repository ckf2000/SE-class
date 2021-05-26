#ifndef SQUARE_H
#define SQUARE_H

#include <QWidget>
#include "mess_box.h"
#include"pagebar.h"

class Square : public QWidget
{
    Q_OBJECT
public:
    explicit Square(QWidget *parent = nullptr);
    Mess_Box mb[4];
    QWidget* getparent(QWidget *parent);
    PageBar pb;
signals:

};


#endif // SQUARE_H
