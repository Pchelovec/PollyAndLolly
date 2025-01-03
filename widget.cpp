#include "widget.h"
#include "ui_widget.h"
#include "gametask.h"
#include <QDebug>
#include <QPainter>
#include"level.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    game=new Game();
    ui->stackedWidget->setCurrentIndex(0);
    qDebug()<<"Welcome to Polly And Lolly Lyric Story!";
}

Widget::~Widget()
{
    delete ui;
}

void Widget::drawScene0(QPaintEvent *pe)
{
    GameTask *gameTask =new GameTask(Level::prolog,Scene::StartMenuScreen_level0);
        gameTask->screenSize=QSize(width(),height());

    QPainter paint(this);
    QPixmap pixmap = game->drawMeScene(gameTask);
    paint.drawPixmap(0, 0, pixmap);
    QWidget::paintEvent(pe);
}

void Widget::paintEvent(QPaintEvent *event)
{
    if (game->changed){
        qDebug()<<"Widget paint for changed screen!";
        drawScene0(event);
    }
    game->changed=false;
}

void Widget::resizeEvent(QResizeEvent *event)
{
    game->changed=true;
    QWidget::update();
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"Mouse pressed";
    //TODO next ui widget
}

void Widget::on_label_clicked()
{
    GameTask *gameTask =new GameTask(Level::prolog,Scene::StartMenuScreen_level0);
        gameTask->screenSize=QSize(width(),height());

        ui->stackedWidget->setCurrentIndex(1);
        game->changed=true;
        QWidget::update();
}
