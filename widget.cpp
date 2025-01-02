#include "widget.h"
#include "ui_widget.h"
#include "gametask.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    game=new Game();
    qDebug()<<"Welcome to Polly And Lolly Lyric Story!";
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
//    game->drawMeScene(new GameTask());
    QPixmap img=game->drawMeScene(new GameTask());
    ui->label->setPixmap(img);
}
