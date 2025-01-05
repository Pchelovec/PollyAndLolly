#include "game.h"
#include"textedstory.h"
#include"patched_game_painter.h"
#include <QWidget>
#include <QPainter>
#include<QPixmap>
#include <QLabel>
#include <QDebug>
Game::Game(QObject *parent) : QObject(parent)
{
    lastPainted=new State();

    //load main backgrounds
    firstBackground.load(":/common/img/background0.png");

    //load main persons
    polly.load(":/sheep/img/sheeps/Polly.png");
    lolly.load(":/sheep/img/sheeps/Lolly.png");
    trolly.load(":/sheep/img/Sheeps/Trolly.png");
}

QPixmap Game::getBacgroundMainScene(QSize screen_size)
{
    return firstBackground.scaled(screen_size.width(),screen_size.height());
}

QPixmap Game::getSheepPolly(QSize screen_size)
{
    return polly.scaled(screen_size.width(),screen_size.height());
}

QPixmap Game::getSheepLolly(QSize screen_size)
{
    return lolly.scaled(screen_size.width(),screen_size.height());
}

QPixmap Game::getResImg(QString path, QSize screen_size)
{
    QPixmap pixmap;
    pixmap.load(path);
    return pixmap.scaled(screen_size.width(),screen_size.height());
}

void Game::taskInfo(GameTask *task)
{
    qDebug()<<"--------------New task !----------------------";
    qDebug()<<"Level:"<<task->level;
    qDebug()<<"Scene:"<<task->scene;
    qDebug()<<"Screen_size"<<task->screenSize;
}

QPixmap* Game::drawScene0_Prolog(GameTask *task)
{
    //prepare extra screenSize calculation
    QSize pollyScreen=QSize((task->screenSize.width()/4),task->screenSize.height()/4);

    //draw
    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0,0,getBacgroundMainScene(task->screenSize));
    gamePainter->draw(0, (task->screenSize.height()/4)*3, getSheepPolly(pollyScreen));
    return gamePainter->process();
}

QPixmap* Game::getSinglePolly(GameTask* task){
    //prepare extra screenSize calculation
    QSize pollyScreen=QSize((task->screenSize.width()),task->screenSize.height());

    //draw
    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0, 0, getSheepPolly(pollyScreen));
    return gamePainter->process();
}

QPixmap *Game::getCoupleSheep(GameTask *task)
{
    //prepare extra screenSize calculation
    QSize polly_lolly_screen=QSize((task->screenSize.width()/2),task->screenSize.height());

    //draw
    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0,0,getResImg(":/levels/level0/img/level0/clipart-heart-background-photography.png",task->screenSize));
    gamePainter->draw(0, 0, getSheepPolly(polly_lolly_screen));
    gamePainter->draw((task->screenSize.width()/2),0,getSheepLolly(polly_lolly_screen));
    return gamePainter->process();
}

QPixmap *Game::getPollySunOrRainImg(GameTask *task)
{
    //prepare extra screenSize calculation
    QSize pollySize=QSize((task->screenSize.width())/3,task->screenSize.height()/3);
    QSize cloudSize=QSize((task->screenSize.width())/4,task->screenSize.height()/4);
    QSize tentSize=QSize(task->screenSize.width()/2,task->screenSize.height());

    //draw
    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0, 0, getResImg(":/levels/level0/img/level0/rain.png",task->screenSize));//
    gamePainter->draw(0, 0,getResImg(":/levels/level0/img/level0/cloud.png",cloudSize));//
    gamePainter->draw(task->screenSize.width()/4*2, 0,getResImg(":/levels/level0/img/level0/cloud.png",cloudSize));//
    gamePainter->draw(0, 0,getResImg(":/levels/level0/img/level0/tent.png",tentSize));
    gamePainter->draw(0, (task->screenSize.height()/3)*2, getSheepPolly(pollySize));
    return gamePainter->process();
}

QPixmap *Game::getPollySunImg(GameTask *task)
{
    //prepare extra screenSize calculation
    QSize pollySize=QSize((task->screenSize.width())/3,task->screenSize.height()/3);
    QSize cloudSize=QSize((task->screenSize.width())/4,task->screenSize.height()/4);
    QSize umbrellaSize=QSize(task->screenSize.width()/4,task->screenSize.height()/4);

    //draw
    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(task->screenSize.width()/2,0,getResImg(":/levels/level0/img/level0/sun.png",cloudSize));
    gamePainter->draw(task->screenSize.width()/2, 0,getResImg(":/levels/level0/img/level0/cloud.png",cloudSize));//
    gamePainter->draw(task->screenSize.width()/4, task->screenSize.height()-umbrellaSize.height()-20,getResImg(":/levels/level0/img/level0/umbrella.png",umbrellaSize));
    gamePainter->draw(0, (task->screenSize.height()/3)*2, getSheepPolly(pollySize));
    return gamePainter->process();
}

QPixmap *Game::drawPollyBeeHouse(GameTask *task)
{
    QSize beeHomeSize=QSize((task->screenSize.width())/2,task->screenSize.height());
    QSize pollySize=QSize((task->screenSize.width())/2,task->screenSize.height()/2);

    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0,0,getResImg(":/levels/level0/img/level0/garden-refuge-captivating-bee-house-scenes-ai-generative-free-png.webp",beeHomeSize));
    gamePainter->draw(task->screenSize.width()/2,task->screenSize.height()/2,getSheepPolly(pollySize));
    return gamePainter->process();
}

QPixmap *Game::drawPollyHoneyDiller(GameTask *task)
{
    QSize pollySize=QSize((task->screenSize.width())/2,task->screenSize.height()/2);
    QSize tabloSize=QSize((task->screenSize.width())/4,task->screenSize.height()/3);

    PatchedGamePainter *gamePainter=new PatchedGamePainter(task->screenSize);
    gamePainter->create();
    gamePainter->draw(0,0,getResImg(":/levels/level0/img/level0/honey-and-honeycombs-illustration.png",task->screenSize));
    gamePainter->draw(task->screenSize.width()/2,task->screenSize.height()/2,getSheepPolly(pollySize));
    gamePainter->draw((task->screenSize.width()/4)*3,(task->screenSize.height()-tabloSize.height()),getResImg(":/levels/level0/img/level0/tablo2_with_sale_text.png",tabloSize));
    return gamePainter->process();
}

State* Game::drawProlog(GameTask *task)
{
    State* sceneToPaint=new State();
    sceneToPaint->level=task->level;
    sceneToPaint->sceneImg=task->scene;
    //    QPixmap *result;
    switch (task->scene) {
    case Prolog_StartMenuScreen:{sceneToPaint->img=*drawScene0_Prolog(task);break;}//
    case Prolog_SinglePollyScene:{sceneToPaint->img=*getSinglePolly(task);sceneToPaint->gameText=textedStory::getPrologText(0);break;}
    case Prolog_TiredPolly:{sceneToPaint->img=*getSinglePolly(task);sceneToPaint->gameText=textedStory::getPrologText(1);break;}
    case Prolog_PollyLookingForAFriend:{sceneToPaint->img=*getSinglePolly(task);sceneToPaint->gameText=textedStory::getPrologText(2);break;}
    case Prolog_PollyDisaster:{sceneToPaint->img=*getSinglePolly(task);sceneToPaint->gameText=textedStory::getPrologText(3);break;}
    case Prolog_PollyUnderRain:{sceneToPaint->img=*getPollySunOrRainImg(task);sceneToPaint->gameText=textedStory::getPrologText(5);break;}
    case Prolog_PollyUnderSun:{sceneToPaint->img=*getPollySunImg(task);sceneToPaint->gameText=textedStory::getPrologText(6);break;}
    case Prolog_PollyPasekaMod:{sceneToPaint->img=*drawPollyBeeHouse(task);sceneToPaint->gameText=textedStory::getPrologText(7);break;}
    case Prolog_PollyRealizatorMod:{sceneToPaint->img=*drawPollyHoneyDiller(task);sceneToPaint->gameText=textedStory::getPrologText(8);break;}
    case Prolog_PollyFindLolly:{sceneToPaint->img=*getSinglePolly(task);sceneToPaint->gameText=textedStory::getPrologText(10);break;}
    case Prolog_LollyMeetPolly:{sceneToPaint->img=*getCoupleSheep(task);sceneToPaint->gameText=textedStory::getPrologText(11);break;}
    case Prolog_LastFrase:{sceneToPaint->img=*getCoupleSheep(task);sceneToPaint->gameText=textedStory::getPrologText(12);break;}

    }

    return sceneToPaint;
}

bool Game::isLastSceneInLevel()
{
    if (lastPainted->sceneImg==Prolog_scene::Prolog_LastFrase){return true;}
    return false;
}

State* Game::drawByTask(GameTask *task)
{
    State *sceneToPaint;
    if (task->level==Level::prolog)
        sceneToPaint=drawProlog(task);
    return sceneToPaint;
}

State* Game::drawMeScene(GameTask *task)
{
    taskInfo(task);
    return drawByTask(task);
}

void Game::debugScene(GameTask *task)
{
    //debug info
    taskInfo(task);

    //label for output
    QLabel *label=new QLabel();

    //extract drawed images
    QPixmap *pixmap = &drawByTask(task)->img;

    //set images to label and show
    label->setPixmap(*pixmap);
    label->resize(task->screenSize);
    label->show();
}
