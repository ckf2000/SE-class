#include "mess_box.h"

Mess_Box::Mess_Box(QWidget *parent) : QWidget(parent)
{
    fbox.show();
    //fbox.move(1000,100);
    fbox.setFixedSize(750,150);
    //fbox.setFrameShape(QFrame::Box);
    fbox.setStyleSheet("border-width: 2px;border-style: solid;border-color: rgb(105,105,105);background-color:rgb(211,211,211)");

    pic.setParent(&fbox);
    pic.setStyleSheet("border-width: 0px;border-style: solid;border-color: rgb(211,211,211);");
    pic.show();
    pic.move(3,3);
    pic.setFixedWidth(144);
    pic.setFixedHeight(144);
    pic.setScaledContents(true);
    pic.setPixmap(QPixmap(":/new/prefix1/icon/pic.jpg"));

    title.setParent(&fbox);
    title.move(160,20);
    title.setStyleSheet("QPushButton{font-weight: bold;font-size: 25px;border-width: 0px;border-style: solid;border-color: rgb(211,211,211,0);}"
                            "QPushButton:hover{font-weight: bold;font-size: 25px;border-width: 0px;color:white;font-style: italic;color: rgb(255,0,0);}");
    title.setText("帮我带只皮卡丘，谢谢！");
    title.show();

    rec.setParent(&fbox);
    rec.move(620,80);
    rec.setFixedSize(100,30);
    rec.setStyleSheet("QPushButton{font-weight: bold;border-radius: 3px;font-size: 20px;border-width: 1px;border-style: solid;border-color: rgb(255,130,71);"
                      "background-color: rgb(255,130,71);color: rgb(255,255,255);}"
                      "QPushButton:hover{font-weight: bold;border-radius: 3px;text-decoration:underline; font-size: 20px;"
                      "border-width: 0px;color:white;color: rgb(255,255,255);}");
    rec.setText("接受订单");
    rec.show();
    rec.setCursor(QCursor(Qt::PointingHandCursor));

    content.setParent(&fbox);
    content.move(260,50);
    content.setFixedSize(340,90);
    content.setStyleSheet("font-size: 15px;border-width: 0px;border-style: solid;border-color: rgb(211,211,211);");
    content.setText("皮卡丘长30cm,宽20cm,高50cm。""\n"
                    "皮卡丘长30cm,宽20cm,高50cm。""\n"
                    "皮卡丘长30cm,宽20cm,高50cm。""\n"
                    "皮卡丘长30cm,宽20cm,高50cm。""\n"
                    "皮卡丘长30cm,宽20cm,高50cm。");
    content.show();

    price.setParent(&fbox);
    price.move(160,100);
    price.setStyleSheet("font-weight: bold;font-size: 40px;border-width: 0px;border-style: solid;border-color: rgb(250,0,0);");
    price.setText("￥10");
    price.show();

    label.setParent(&fbox);
    label.move(165,55);
    label.setStyleSheet("font-size: 15px;border-width: 1px;border-radius: 6px;background-color: rgb(0,191,255);border-style: solid;color: rgb(255,255,255);");
    label.setText("带饭");
    label.show();

    time.setParent(&fbox);
    time.move(550,20);
    time.setStyleSheet("font-size: 20px;border-width: 0px;border-style: solid;border-color: rgb(211,211,211);");
    time.setText("发布时间：5分钟前");
    time.show();
}

void Mess_Box::lomove(int num){
    fbox.move(200,num*160+100);
}
