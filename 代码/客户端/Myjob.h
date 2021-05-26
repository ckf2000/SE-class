#ifndef MYJOB_H
#define MYJOB_H
#include<QFile>
#include<fstream>
#include<QDataStream>
#include<QMainWindow>
#include<jobsquare.h>
#include"MyStruct.h"
#include"MyClient.h"
#include<vector>
namespace Ui {
class Myjob;
}

class Myjob : public QMainWindow
{
    Q_OBJECT

public:
    explicit Myjob(QWidget *parent = 0);
    ~Myjob();
    char superID[50];
    void mytask();
    //task mytasks[5];
    vector<task>mytasks;
private:
    Ui::Myjob *ui;
    JobSquare jobsq;
};
#endif // MYJOB_H
