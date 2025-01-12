#ifndef STATE_H
#define STATE_H

#include <QObject>
#include<QPixmap>
#include<QString>
#include "level.h"
class State : public QObject
{
    Q_OBJECT
public:
    explicit State(QObject *parent = nullptr);
    State(Level l,Prolog_scene s);
    Level level;
    Prolog_scene sceneImg;
    QString gameText;
    QPixmap img;

private:

};
//QDataStream &operator<<(QDataStream &out, const State &progress);
//QDataStream &operator>>(QDataStream &in, State &progress);
#endif // STATE_H
