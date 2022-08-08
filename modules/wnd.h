#include "SFML/Graphics.hpp"
#define TITLE "Airport"
#define BGFILENAME "airport.png"
#define LENGHTWND 1800
#define WIDTHWND 840


using namespace sf;
using namespace std;

struct sizeWindow
{
    int lenght;
    int width;
     
    void setMembers(int len, int wid);
};

class mapping
{
    private:
        string titleWnd;
        sizeWindow sizeWnd;
        string backgroundNameFile;
        vector<Sprite> elements;
        Texture texture;

    public:
        int createWindow();
        mapping();
        int addElement(RenderWindow *window, string pathimg);
        int delElement(RenderWindow *window, int index);
        Sprite getSprite(int index);
        Texture getTexture();
                
};
