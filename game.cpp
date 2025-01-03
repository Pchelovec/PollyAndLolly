#include "game.h"
#include <QWidget>
#include <QPainter>
#include<QPixmap>
#include <QLabel>
#include <QDebug>
Game::Game(QObject *parent) : QObject(parent)
{
    state=new State();

    firstBackground.load(":/common/img/background0.png");
    polly.load(":/sheep/img/sheeps/Polly.png");
}

QPixmap Game::getBacgroundMainScene(QSize screen_size)
{
    return firstBackground.scaled(screen_size.width(),screen_size.height());
}

QPixmap Game::getSheepPolly(QSize screen_size)
{
    return polly.scaled(screen_size.width(),screen_size.height());
}

void Game::taskInfo(GameTask *task)
{
    qDebug()<<"--------------New task !----------------------";
    qDebug()<<"Level:"<<task->level;
    qDebug()<<"Scene:"<<task->scene;
    qDebug()<<"Screen_size"<<task->screenSize;
}

QPixmap Game::drawScene0_Prolog(GameTask *task)
{
    QPixmap *pixmap=new QPixmap(task->screenSize);
    pixmap->fill(Qt::transparent);
    QPainter *painter=new QPainter(pixmap);
    painter->drawPixmap(0, 0,getBacgroundMainScene(task->screenSize));

    QSize pollyScreen=QSize((task->screenSize.width()/4),task->screenSize.height()/4);
    painter->drawPixmap(0, (task->screenSize.height()/4)*3, getSheepPolly(pollyScreen));
    painter->end();
    return *pixmap;
}

QPixmap Game::drawByTask(GameTask *task)
{
    QPixmap result;
    if (task->level==Level::prolog and task->scene==Scene::StartMenuScreen_level0){
        result = drawScene0_Prolog(task);
    }

    return result;
}

QPixmap Game::drawMeScene(GameTask *task)
{
    taskInfo(task);
    QPixmap pixmap = drawByTask(task);
    return pixmap;
}

void Game::debugScene(GameTask *task)
{
    QLabel *label=new QLabel();

    QPixmap pixmap = drawByTask(task);

    label->setPixmap(pixmap);
    label->resize(task->screenSize);
    label->show();
}
