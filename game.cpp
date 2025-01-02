#include "game.h"
#include <QWidget>
#include <QPainter>
#include<QPixmap>
#include <QLabel>
Game::Game(QObject *parent) : QObject(parent)
{
    state=new State();

    firstBackground.load(":/common/img/background0.png");
    polly.load(":/sheep/img/sheeps/Polly.png");
}

QPixmap Game::getBacgroundMainScene(int w,int h)
{
    return firstBackground.scaled(w,h);
}

//************************************************
//TODO fix for QWidget
//QWidget *w = new QWidget();
//QPainter paint(w);
//QPixmap pixmap = getBacgroundMainScene(600,800);
//paint.drawPixmap(0, 0, pixmap);
//w->show();
QPixmap Game::drawMeScene(GameTask *task)
{
    //step 1 -create pixmap by task
    QPainter paint;
    QPixmap pixmap = getBacgroundMainScene(600,800);
    paint.drawPixmap(0, 0, pixmap);

    //step 2 - show pixmap
    QLabel *l = new QLabel;
    l->setPixmap(pixmap);
    l->setAttribute(Qt::WA_DeleteOnClose);
    l->show();

    //step 3 - return pixmap
    return pixmap;
}
