#include "square.h"

Square::Square(QWidget *parent) : QWidget(parent)
{

}

QWidget* Square::getparent(QWidget *parent){
    pb.setParent(parent);
    pb.move(300,740);
    pb.setFixedSize(400,100);
    pb.init(parent);
    return parent;
}
