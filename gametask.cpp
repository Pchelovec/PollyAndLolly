#include "gametask.h"

GameTask::GameTask(QObject *parent) : QObject(parent)
{

}

GameTask::GameTask(Level l, Prolog_scene s)
{
    this->level=l;
    this->scene=s;
    this->screenSize= QSize(default_w,default_h);
}
