#include "SFML/Graphics.hpp"

using namespace sf;
using namespace std;


template<typename typePlane>
struct message;
class manager;
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
        virtual int takeoff(RenderWindow *window, Sprite background, Text text) = 0;
        virtual int landing(RenderWindow *window, Sprite background, Text text) = 0;
        void setSprite(Sprite sprite);
        Sprite getSprite();
        void setIndex(int index);
        int getIndex();
        string getName();
        int getAddWeight();
        int getPerLvlFuel();
        int getMaxAddWeight();
        void updateVarParam();
        template<typename typePlane>
        message<typePlane> generateMsg(manager mgr);
};

class boeing_787 : public airship
{
    public:
        boeing_787();
        boeing_787(Sprite sprite, Texture texture, int index);
        int takeoff(RenderWindow *window, Sprite background, Text text) override;
        int landing(RenderWindow *window, Sprite background, Text text) override;

};

class cessnaM : public airship
{
    public:
        cessnaM();
        cessnaM(Sprite sprite, Texture texture, int index);
        int takeoff(RenderWindow *window, Sprite background, Text text) override;
        int landing(RenderWindow *window, Sprite background, Text text) override;
};


class cirrus : public airship
{
    public:
        cirrus();
        cirrus(Sprite sprite, Texture texture, int index);
        int takeoff(RenderWindow *window, Sprite background, Text text) override;
        int landing(RenderWindow *window, Sprite background, Text text) override;
};
