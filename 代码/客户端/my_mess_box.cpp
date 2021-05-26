#include"my_mess_box.h"

My_Mess_Box::My_Mess_Box(QWidget *parent) : QWidget(parent)
{

}

void My_Mess_Box::lomove(int num){
    fbox.move(200,num*160+100);
}
void My_Mess_Box::changeui(task mytask)
{
    //主小窗口
    fbox.show();
    fbox.move(200,100);
    fbox.setFixedSize(750,150);
    //fbox.setFrameShape(QFrame::Box);
    fbox.setStyleSheet("border-width: 2px;border-style: solid;border-color: rgb(105,105,105);background-color:rgb(211,211,211)");
    //加载图片
    pic.setParent(&fbox);
    pic.setStyleSheet("border-width: 0px;border-style: solid;border-color: rgb(211,211,211);");
    pic.show();
    pic.move(3,3);
    pic.setFixedWidth(144);
    pic.setFixedHeight(144);
    pic.setScaledContents(true);

    //注意这里改图片改成自己的路径

    pic.setPixmap(QPixmap(":/new/prefix1/icon/pic.jpg"));
    //题目
    title.setParent(&fbox);
    title.move(160,20);
    title.setStyleSheet("QPushButton{font-weight: bold;font-size: 25px;border-width: 0px;border-style: solid;border-color: rgb(211,211,211,0);}"
                        "QPushButton:hover{font-weight: bold;font-size: 25px;border-width: 0px;color:white;font-style: italic;color: rgb(255,0,0);}");
   title.setText("看这里有一个任务");
    title.show();
    //控件
    delete_.setParent(&fbox);
    delete_.move(620,30);
    delete_.setFixedSize(100,30);
    delete_.setStyleSheet("QPushButton{font-weight: bold;border-radius: 3px;font-size: 20px;border-width: 1px;border-style: solid;border-color: rgb(255,130,71);"
                          "background-color: rgb(255,130,71);color: rgb(255,255,255);}"
                          "QPushButton:hover{font-weight: bold;border-radius: 3px;text-decoration:underline; font-size: 20px;"
                          "border-width: 0px;color:white;color: rgb(255,255,255);}");
    delete_.setText("删除");
    delete_.show();
    delete_.setCursor(QCursor(Qt::PointingHandCursor));
    connect(&delete_,&QPushButton::clicked,this,&My_Mess_Box::deletemyWight);
    //文本内容
    content.setParent(&fbox);
    content.move(260,50);
    content.setFixedSize(340,90);
    content.setStyleSheet("font-size: 15px;border-width: 0px;border-style: solid;border-color: rgb(211,211,211);");
    content.setText(mytask.content);
    content.show();
    //价格
    price.setParent(&fbox);
    price.move(160,100);
    price.setStyleSheet("font-weight: bold;font-size: 40px;border-width: 0px;border-style: solid;border-color: rgb(250,0,0);");
    QString temp=QString::number(mytask.price,10,2);
    temp="￥"+temp;
    //这里改一下价格
    price.setText(temp);
    price.show();
    //标签
    label.setParent(&fbox);
    label.move(165,55);
    label.setStyleSheet("font-size: 15px;border-width: 1px;border-radius: 6px;background-color: rgb(0,191,255);border-style: solid;color: rgb(255,255,255);");
    //注意改标签


    //if(mytask.label==1)
    label.setText("快递");
    label.show();

}
void My_Mess_Box::deletemyWight()
{
    fbox.close();
    char ip[16]="192.168.43.182";
    MyClient myclient(ip,1234);
    sign_in s;
    for(int i=0;i<50;i++)
        s.ID[i]=superID[i];
    myclient.Clisend(MYTASK,s);
    //发送删除此条任务的消息

}

