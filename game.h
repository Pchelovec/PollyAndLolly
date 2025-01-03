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
    State *state;
    QPixmap drawMeScene(GameTask *task);
    void debugScene(GameTask *task);
    bool changed;



private:
    QPixmap firstBackground;
    QPixmap polly;
    QPixmap getBacgroundMainScene(QSize screen_size);
    QPixmap getSheepPolly(QSize screen_size);

    void taskInfo(GameTask * task);
    QPixmap drawScene0Prolog(GameTask *task);
    QPixmap drawTempalteSceneByTask(GameTask *task);
    QPixmap drawScene0_Prolog(GameTask *task);

    QPixmap drawByTask(GameTask *task);
};

#endif // GAME_H
