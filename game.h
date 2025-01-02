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

private:
    QPixmap firstBackground;
    QPixmap polly;
    QPixmap getBacgroundMainScene(int w,int h);
};

#endif // GAME_H
