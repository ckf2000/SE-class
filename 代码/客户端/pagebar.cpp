#include "pagebar.h"

PageBar::PageBar(QWidget *parent) : QWidget(parent)
{
    currentpage=1;
    bar.move(300,740);
    bar.setFixedSize(400,100);
    //bar.show();

}


void PageBar::init(QWidget *parent){
    bar.setParent(parent);
    ellipsis1.setParent(&bar);
    ellipsis2.setParent(&bar);
    turnbef.setParent(&bar);
    turnback.setParent(&bar);
    num_page.setParent(&bar);

    for(int i=0;i<6;i++){
        page[i].setParent(&bar);
        QString name;
        name=QString::number(i+1);
        page[i].setFixedSize(30,27);
        page[i].setText(name);
        page[i].setStyleSheet("font-size: 15px;color: rgb(0,0,0);border-color: rgb(0,0,0);background-color: rgb(255,255,255);");
        page[i].hide();
    }
    connect(&page[0],&QPushButton::clicked,this,&PageBar::skipto0);
    connect(&page[1],&QPushButton::clicked,this,&PageBar::skipto1);
    connect(&page[2],&QPushButton::clicked,this,&PageBar::skipto2);
    connect(&page[3],&QPushButton::clicked,this,&PageBar::skipto3);
    connect(&page[4],&QPushButton::clicked,this,&PageBar::skipto4);
    connect(&page[5],&QPushButton::clicked,this,&PageBar::skipto5);
    for(int i=0;i<3;i++){
    page[i].move(65+i*35,0);
    page[i].show();
    }
    page[0].setStyleSheet("font-size: 15px;color: rgb(255,255,255);border-color: rgb(255,69,0);background-color: rgb(255,69,0);");
    page[0].setDisabled(true);

    turnback.move(195,0);
    turnback.setFixedSize(60,27);
    turnback.setText("下一页>");
    turnback.setStyleSheet("font-size: 15px;color: rgb(0,0,0);border-color: rgb(0,0,0);background-color: rgb(255,255,255);");
    turnback.show();
    connect(&turnback,&QPushButton::clicked,this,&PageBar::nextpage);

    turnbef.move(0,0);
    turnbef.setFixedSize(60,27);
    turnbef.setText("<上一页");
    turnbef.setStyleSheet("font-size: 15px;color: rgb(0,0,0);border-color: rgb(0,0,0);background-color: rgb(255,255,255);");
    //turnbef.hide();
    turnbef.show();
    connect(&turnbef,&QPushButton::clicked,this,&PageBar::beforepage);

    ellipsis1.setText("......");
    ellipsis1.move(100,15);
    ellipsis1.setStyleSheet("font-size: 10px;color: rgb(0,0,0);");
    ellipsis1.hide();


    ellipsis2.setText("...");
    ellipsis2.move(175,15);
    ellipsis2.setStyleSheet("font-size: 10px;color: rgb(0,0,0);");
    ellipsis2.show();

    num_page.move(380,0);
    num_page.setFixedSize(30,30);
    QString str=QString::number(currentpage);
    num_page.setText(str);
    num_page.show();
}

void PageBar::nextpage(){
    if(currentpage<25){
        currentpage++;
        QString str=QString::number(currentpage);
        num_page.setText(str);
        num_page.show();
        if(currentpage==2){
            page[0].setEnabled(true);
            page[0].setStyleSheet("font-size: 15px;color: rgb(0,0,0);border-color: rgb(0,0,0);background-color: rgb(255,255,255);");
            page[3].move(65+3*35,0);
            page[3].show();
            ellipsis2.move(210,15);
            turnback.move(230,0);
            page[1].setStyleSheet("font-size: 15px;color: rgb(255,255,255);border-color: rgb(255,69,0);background-color: rgb(255,69,0);");
            page[1].setDisabled(true);
        }
        else if(currentpage==3){
            page[1].setEnabled(true);
            page[1].setStyleSheet("font-size: 15px;color: rgb(0,0,0);border-color: rgb(0,0,0);background-color: rgb(255,255,255);");
            page[4].move(65+4*35,0);
            page[4].show();
            ellipsis2.move(245,15);
            turnback.move(265,0);
            page[2].setStyleSheet("font-size: 15px;color: rgb(255,255,255);border-color: rgb(255,69,0);background-color: rgb(255,69,0);");
            page[2].setDisabled(true);
        }
        else if(currentpage==4){
            page[2].setEnabled(true);
            page[2].setStyleSheet("font-size: 15px;color: rgb(0,0,0);border-color: rgb(0,0,0);background-color: rgb(255,255,255);");
            page[5].move(65+5*35,0);
            page[5].show();
            ellipsis2.move(280,15);
            turnback.move(300,0);
            page[3].setStyleSheet("font-size: 15px;color: rgb(255,255,255);border-color: rgb(255,69,0);background-color: rgb(255,69,0);");
            page[3].setDisabled(true);
        }
        else if(currentpage==24){
            page[3].setEnabled(true);
            page[3].setStyleSheet("font-size: 15px;color: rgb(0,0,0);border-color: rgb(0,0,0);background-color: rgb(255,255,255);");
            page[4].setStyleSheet("font-size: 15px;color: rgb(255,255,255);border-color: rgb(255,69,0);background-color: rgb(255,69,0);");
            page[4].setDisabled(true);
        }
        else if(currentpage==25){
            page[4].setEnabled(true);
            page[4].setStyleSheet("font-size: 15px;color: rgb(0,0,0);border-color: rgb(0,0,0);background-color: rgb(255,255,255);");
            page[5].setStyleSheet("font-size: 15px;color: rgb(255,255,255);border-color: rgb(255,69,0);background-color: rgb(255,69,0);");
            page[5].setDisabled(true);
        }
        else{
            page[1].hide();
            ellipsis1.show();
            for(int i=2;i<6;i++){
                QString num=QString::number(currentpage+i-3);
                page[i].setText(num);
            }
        }
    }
    else return;
}

void PageBar::beforepage(){
    if(currentpage>1){
        currentpage--;
        QString str=QString::number(currentpage);
        num_page.setText(str);
        num_page.show();
        if(currentpage==1){
            page[1].setEnabled(true);
            page[1].setStyleSheet("font-size: 15px;color: rgb(0,0,0);border-color: rgb(0,0,0);background-color: rgb(255,255,255);");
            //page[3].move(65+3*35,0);
            page[3].hide();
            ellipsis2.move(175,15);
            turnback.move(195,0);
            page[0].setStyleSheet("font-size: 15px;color: rgb(255,255,255);border-color: rgb(255,69,0);background-color: rgb(255,69,0);");
            page[0].setDisabled(true);
        }
        else if(currentpage==2){
            page[2].setEnabled(true);
            page[2].setStyleSheet("font-size: 15px;color: rgb(0,0,0);border-color: rgb(0,0,0);background-color: rgb(255,255,255);");
            //page[3].move(65+3*35,0);
            page[4].hide();
            ellipsis2.move(210,15);
            turnback.move(230,0);
            page[1].setStyleSheet("font-size: 15px;color: rgb(255,255,255);border-color: rgb(255,69,0);background-color: rgb(255,69,0);");
            page[1].setDisabled(true);
        }
        else if(currentpage==3){
            page[3].setEnabled(true);
            page[3].setStyleSheet("font-size: 15px;color: rgb(0,0,0);border-color: rgb(0,0,0);background-color: rgb(255,255,255);");
            //page[4].move(65+4*35,0);
            page[5].hide();
            ellipsis2.move(245,15);
            turnback.move(265,0);
            page[2].setStyleSheet("font-size: 15px;color: rgb(255,255,255);border-color: rgb(255,69,0);background-color: rgb(255,69,0);");
            page[2].setDisabled(true);
        }
        else if(currentpage==4){
            for(int i=2;i<6;i++){
                QString num=QString::number(currentpage+i-3);
                page[i].setText(num);
            }
            //page[3].setEnabled(true);
            //page[3].setStyleSheet("font-size: 15px;color: rgb(0,0,0);border-color: rgb(0,0,0);background-color: rgb(255,255,255);");
            //page[5].move(65+5*35,0);
            page[1].show();
            ellipsis1.hide();
            ellipsis2.move(280,15);
            turnback.move(300,0);
            //page[2].setStyleSheet("font-size: 15px;color: rgb(255,255,255);border-color: rgb(255,69,0);background-color: rgb(255,69,0);");
            //page[2].setDisabled(true);
        }
        else if(currentpage==23){
            page[4].setEnabled(true);
            page[4].setStyleSheet("font-size: 15px;color: rgb(0,0,0);border-color: rgb(0,0,0);background-color: rgb(255,255,255);");
            page[3].setStyleSheet("font-size: 15px;color: rgb(255,255,255);border-color: rgb(255,69,0);background-color: rgb(255,69,0);");
            page[3].setDisabled(true);
        }
        else if(currentpage==24){
            page[5].setEnabled(true);
            page[5].setStyleSheet("font-size: 15px;color: rgb(0,0,0);border-color: rgb(0,0,0);background-color: rgb(255,255,255);");
            page[4].setStyleSheet("font-size: 15px;color: rgb(255,255,255);border-color: rgb(255,69,0);background-color: rgb(255,69,0);");
            page[4].setDisabled(true);
        }
        else{
            page[1].hide();
            ellipsis1.show();
            for(int i=2;i<6;i++){
                QString num=QString::number(currentpage+i-3);
                page[i].setText(num);
            }
        }
    }
    else return;
}

void PageBar::skipto0(){
    if(currentpage!=1){
        currentpage=1;
        QString pagenum=QString::number(currentpage);
        for(int i=0;i<6;i++){
            QString name;
            name=QString::number(i+1);
            page[i].setFixedSize(30,27);
            page[i].setText(name);
            page[i].setStyleSheet("font-size: 15px;color: rgb(0,0,0);border-color: rgb(0,0,0);background-color: rgb(255,255,255);");
            page[i].hide();
        }
        for(int i=0;i<3;i++){
        page[i].move(65+i*35,0);
        page[i].show();
        }
        page[0].setStyleSheet("font-size: 15px;color: rgb(255,255,255);border-color: rgb(255,69,0);background-color: rgb(255,69,0);");
        page[0].setDisabled(true);

        turnback.move(195,0);
        turnback.show();

        turnbef.move(0,0);
        turnbef.show();

        ellipsis1.hide();

        ellipsis2.move(175,15);
        ellipsis2.show();
    }
}

void PageBar::skipto1(){
    if(currentpage!=2){
        skipto0();
        nextpage();
    }
}

void PageBar::skipto2(){
    if(currentpage==1||currentpage==4){
        skipto1();
        nextpage();
    }
    else if(currentpage==2){
        nextpage();
    }
    else if(currentpage>4&&currentpage<24){
        beforepage();
    }
    else if(currentpage==24){
        beforepage();
        beforepage();
    }
    else if(currentpage==25){
        beforepage();
        beforepage();
        beforepage();
    }
}

void PageBar::skipto3(){
    if(currentpage==2){
        nextpage();
        nextpage();
    }
    else if(currentpage==3){
        nextpage();
    }
    else if(currentpage==24){
        beforepage();
    }
    else if(currentpage==25){
        beforepage();
        beforepage();
    }
}

void PageBar::skipto4(){
    if(currentpage==3){
        nextpage();
        nextpage();
    }
    else if(currentpage>3&&currentpage<24){
        nextpage();
    }
    else if(currentpage==25){
        beforepage();
    }
}

void PageBar::skipto5(){
    if(currentpage<24){
        nextpage();
        nextpage();
    }
    else if(currentpage==24){
        nextpage();
    }
}
