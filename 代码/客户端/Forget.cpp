#include "Forget.h"
#include "ui_Forget.h"

Forget::Forget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Forget)
{
    ui->setupUi(this);
}

Forget::~Forget()
{
    delete ui;
}
