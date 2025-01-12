#include "state.h"

State::State(QObject *parent) : QObject(parent)
{
    this->level=Level::PROLOG;
    this->sceneImg=Prolog_scene::Prolog_StartMenuScreen;
}

State::State(Level l, Prolog_scene s)
{
    this->level=l;
    this->sceneImg=s;
}

//QDataStream &operator<<(QDataStream &out, const State &progress)
//{
//    qDebug()<<"save "<<progress.level;
//    out << progress.level;
//    return out;
//}

//QDataStream &operator>>(QDataStream &in, State &progress)
//{
//    int level;
//    in >> level;
//    qDebug()<<"restored"<<level;
//    progress.level=static_cast<Level>(level);
//    return in;
//}
