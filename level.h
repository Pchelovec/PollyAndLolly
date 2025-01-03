#ifndef LEVEL_H
#define LEVEL_H

//#include "gametask.h"
#include<QDebug>
enum Level{
    prolog,
    walk,
    journey,
    voyage
};

enum Prolog_scene{
    Prolog_StartMenuScreen,
    Prolog_SinglePollyScene,
    Prolog_TiredPolly,
    Prolog_PollyLookingForAFriend,
    Prolog_PollyDisaster,
    Prolog_PollyUnderRain,
    Prolog_PollyUnderSun,
    Prolog_PollyPasekaMod,
    Prolog_PollyRealizatorMod,
    Prolog_PollyFindLolly,
    Prolog_LollyMeetPolly,
    Prolog_LastFrase
};
inline Prolog_scene& operator++(Prolog_scene& mode, const int){
        qDebug()<<"MODE"<<mode;
        mode = static_cast<Prolog_scene>((mode + 1));
        return mode;
}
#endif // LEVEL_H
