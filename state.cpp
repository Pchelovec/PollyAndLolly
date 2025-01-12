#include "state.h"

Scene::Scene(QObject *parent) : QObject(parent)
{
    this->level=Level::PROLOG;
    this->screen=Prolog_scene::Prolog_StartMenuScreen;
}

Scene::Scene(Level l, Screen s)
{
    this->level=l;
    this->screen=s;
}

void Scene::incrementScene()
{
    screen++;
}
