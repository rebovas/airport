#pragma once
#include "SFML/Graphics.hpp"
#include <random>
#include <time.h>
#include <math.h>
#include <type_traits>
#include "airship.h"
#include <iostream>

using namespace sf;
using namespace std;

enum levelRain {Nope, Light, Medium, Heavy};
enum modelPlane {Boeing787, CessnaCitation, CirrusSR};

template<typename typePlane>
struct message;

struct anwManager
{
    string solution;
    modelPlane model;
    typeAction action;
    bool allowAct;
};

class manager
{
    private:
        float windSpeed;
        bool snow;
        levelRain rain;
        bool runwayBusy;

        int chanceRain;
        int chanceSnow;

    public:
        manager(RenderWindow *window, Sprite background, Text &text);
        void update(RenderWindow *window, Sprite background, Text &text);
        anwManager getResultManager(message<boeing_787> msg);
        anwManager getResultManager(message<cessnaM> msg);
        anwManager getResultManager(message<cirrus> msg);
        void chngStatusRunway(bool status);

};

