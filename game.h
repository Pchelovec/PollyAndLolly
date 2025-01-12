#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QPixmap>
#include "state.h"
#include "gametask.h"
#include "progress.h"
class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = nullptr);
    Scene *lastPainted;
    Scene* drawMeScene(GameTask *task);
    void debugScene(GameTask *task);
    bool changed;

    bool isLastSceneInLevel();
    void saveProgress();
    void loadProgress();

private:
    QPixmap firstBackground;
    QPixmap polly;
    QPixmap lolly;
    QPixmap trolly;
    QPixmap getBacgroundMainScene(QSize screen_size);
    QPixmap getSheepPolly(QSize screen_size);
    QPixmap getSheepLolly(QSize screen_size);

    QPixmap getResImg(QString path,QSize screen_size);


    void taskInfo(GameTask * task);
    QPixmap* drawScene0_Prolog(GameTask *task);
    QPixmap* getSinglePolly(GameTask *task);
    QPixmap* getCoupleSheep(GameTask *task);
    QPixmap* getPollySunOrRainImg(GameTask *task);
    QPixmap* getPollySunImg(GameTask *task);
    QPixmap* drawPollyBeeHouse(GameTask *task);
    QPixmap* drawPollyHoneyDiller(GameTask *task);


    Scene* drawByTask(GameTask *task);
    Scene* drawProlog(GameTask *task);

};

#endif // GAME_H
