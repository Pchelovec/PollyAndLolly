#include "state.h"

State::State(QObject *parent) : QObject(parent)
{
    this->level=Level::prolog;
    this->sceneImg=Prolog_scene::Prolog_StartMenuScreen;
}

State::State(Level l, Prolog_scene s)
{
    this->level=l;
    this->sceneImg=s;
}
