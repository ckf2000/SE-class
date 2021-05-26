#ifndef FORGET_H
#define FORGET_H

#include <QMainWindow>

namespace Ui {
class Forget;
}

class Forget : public QMainWindow
{
    Q_OBJECT

public:
    explicit Forget(QWidget *parent = 0);
    ~Forget();

private:
    Ui::Forget *ui;
};

#endif // FORGET_H
