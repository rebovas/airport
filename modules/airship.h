#pragma once
#include "SFML/Graphics.hpp"
#include <random>
#include <iostream>
#include <type_traits>

using namespace sf;
using namespace std;

enum typeAction {Takeoff, Landing};

class visibleElm
{
    private:
        Sprite* stackSprite;
        int currIndxSprite;
        Text* stackText;
        int currIndxTexture;
    public:
        visibleElm();
        void add(Sprite& sprite);
        void add(Text& text);
        void reload(RenderWindow *window);
};

template<typename typePlane>
struct message
{
    string generateMsg;
    typeAction action;
    typePlane plane;
};

void ClearPolEvent(RenderWindow *window);

class airship
{
    protected:
        Sprite sprite;
        Texture texture;
        string name;
        int weight;
        int addWeight;
        int maxAddWeight;
        int index;
        int tankVolume;
        int currentLvlFuel;

    public:
        virtual int takeoff(RenderWindow *window, visibleElm elms) = 0;
        virtual int landing(RenderWindow *window, visibleElm elms) = 0;
        void setSprite(Sprite sprite);
        Sprite getSprite();
        void setIndex(int index);
        int getIndex();
        string getName();
        int getAddWeight();
        int getPerLvlFuel();
        int getMaxAddWeight();
        void updateVarParam();
};

class boeing_787 : public airship
{
    public:
        boeing_787();
        boeing_787(Sprite sprite, Texture texture, int index);
        int takeoff(RenderWindow *window, visibleElm elms) override;
        int landing(RenderWindow *window, visibleElm elms) override;
        message<boeing_787> generateMsg();
};

class cessnaM : public airship
{
    public:
        cessnaM();
        cessnaM(Sprite sprite, Texture texture, int index);
        int takeoff(RenderWindow *window, visibleElm elms) override;
        int landing(RenderWindow *window, visibleElm elms) override;
        message<cessnaM> generateMsg();
};


class cirrus : public airship
{
    public:
        cirrus();
        cirrus(Sprite sprite, Texture texture, int index);
        int takeoff(RenderWindow *window, visibleElm elms) override;
        int landing(RenderWindow *window, visibleElm elms) override;
        message<cirrus> generateMsg();
};
