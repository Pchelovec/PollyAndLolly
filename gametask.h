#ifndef GAMETASK_H
#define GAMETASK_H

#include <QObject>
#include <QSize>
#include "level.h"
class GameTask : public QObject
{
    Q_OBJECT
public:
    explicit GameTask(QObject *parent = nullptr);
    GameTask(Level l,Prolog_scene s);
    Level level;
    Prolog_scene scene;
    QSize screenSize;

private:
    int default_w=400;
    int default_h=600;
};

#endif // GAMETASK_H
