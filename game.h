#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QPixmap>
#include "state.h"
#include "gametask.h"

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = nullptr);
    State *lastPainted;
    State* drawMeScene(GameTask *task);
    void debugScene(GameTask *task);
    bool changed;



    State* drawProlog(GameTask *task);

private:
    QPixmap firstBackground;
    QPixmap polly;
    QPixmap lolly;
    QPixmap getBacgroundMainScene(QSize screen_size);
    QPixmap getSheepPolly(QSize screen_size);
    QPixmap getSheepLolly(QSize screen_size);


    void taskInfo(GameTask * task);
//    QPixmap drawScene0Prolog(GameTask *task);
//    QPixmap drawTempalteSceneByTask(GameTask *task);
    QPixmap* drawScene0_Prolog(GameTask *task);
    QPixmap* getSingleLolly(GameTask *task);
    QPixmap* getCoupleSheep(GameTask *task);


    State* drawByTask(GameTask *task);
};

#endif // GAME_H
