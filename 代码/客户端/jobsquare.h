#ifndef JOBSQUARE_H
#define JOBSQUARE_H
#include <QWidget>
#include<my_mess_box.h>
#include<vector>
class JobSquare : public QWidget
{
    Q_OBJECT
public:
    explicit JobSquare(QWidget *parent = nullptr);
    My_Mess_Box mmb[5];
signals:

};
#endif // JOBSQUARE_H
