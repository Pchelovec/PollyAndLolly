#include "gametask.h"

GameTask::GameTask(QObject *parent) : QObject(parent)
{
    this->level=Level::prolog;
    this->scene=Prolog_scene::Prolog_SinglePollyScene;
    this->screenSize = QSize(default_w,default_h);
}

GameTask::GameTask(Level l, Prolog_scene s)
{
    this->level=l;
    this->scene=s;
    this->screenSize = QSize(default_w,default_h);
}
