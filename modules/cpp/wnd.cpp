#include "../wnd.h" 

#define PATHIMGS "../img/"

void sizeWindow::setMembers(int len, int wid)
{
    this->lenght = len;
    this->width = wid;
};

int mapping::addElement(RenderWindow *window, string pathimg)
{
    Texture texture;

    if(!texture.loadFromFile(pathimg))
    {
        return EXIT_FAILURE;
    }

    this->texture = texture;

    Sprite sprite(texture);

    this->elements.push_back(sprite);
    return 0;
};

Texture mapping::getTexture()
{
    return this->texture;
};

int mapping::createWindow()
{
    mapping objs;
    Texture texture;
    default_random_engine generator;
    generator.seed(time(0));
    uniform_int_distribution<int> distributionPlane(1, 90);
    distributionPlane(generator);
    uniform_int_distribution<int> distributionSecAct(1, 10);
    distributionSecAct(generator);
    int secsAct = distributionSecAct(generator), secsWaitPlane = 0;
    Clock clock, clock2, clock3;
    Time time = clock.restart(), time2 = clock2.restart(), time3 = clock3.restart();
    anwManager anwMan, anwManSaved;

    if(!texture.loadFromFile((string)PATHIMGS + BGFILENAME))
    {
        return EXIT_FAILURE;
    }

    Sprite bg(texture);
    Font font;

    if(!font.loadFromFile("../img/fonts/OpenSans-Bold.ttf"))
    {
        return EXIT_FAILURE;
    }
    Text text;
    text.setFont(font);
    text.setCharacterSize(14);
    text.setFillColor(Color::Black);
    text.setPosition(1600, 0);

    RenderWindow *window = new RenderWindow(VideoMode(this->sizeWnd.lenght, this->sizeWnd.width), this->titleWnd, Style::Close);    
    manager manager(window, bg, text);

    
    objs.addElement(window, (string)PATHIMGS + "White large plane.png");
    boeing_787 boeing(objs.getSprite(0), objs.getTexture(), 0);
    objs.addElement(window, (string)PATHIMGS + "White medium plane.png");
    cessnaM cessnaJet(objs.getSprite(1), objs.getTexture(), 1);
    objs.addElement(window, (string)PATHIMGS + "White small plane.png");
    cirrus cirrusSR(objs.getSprite(2), objs.getTexture(), 2);
    
    while (window->isOpen())
    {
        time3 = clock3.getElapsedTime();
        time = clock.getElapsedTime();
        if(secsWaitPlane != 0)
        {
            time2 = clock2.getElapsedTime();
        }
        ClearPolEvent(window);

        if(time.asSeconds() >= secsAct)
        {
            secsAct = distributionSecAct(generator);
            time = time.Zero;
            clock.restart();

            switch((modelPlane)(distributionPlane(generator) % 3))
            {
                case modelPlane::Boeing787:anwMan = manager.getResultManager(boeing.generateMsg()); break;
                case modelPlane::CessnaCitation:anwMan = manager.getResultManager(cessnaJet.generateMsg()); break;
                case modelPlane::CirrusSR:anwMan = manager.getResultManager(cirrusSR.generateMsg()); break;
                default: break;
            }

            if(anwMan.allowAct)
            {
                secsWaitPlane = distributionSecAct(generator); 
                time2 = time2.Zero;
                clock2.restart();
                anwManSaved = anwMan;
            }
            else
            {
                switch(anwMan.model)
                {
                    case modelPlane::Boeing787: boeing.updateVarParam(); break;
                    case modelPlane::CessnaCitation: cessnaJet.updateVarParam(); break;
                    case modelPlane::CirrusSR: cirrusSR.updateVarParam(); break;
                }
            }
        }

        if(secsWaitPlane < time2.asSeconds())
        {
            secsWaitPlane = 0;
            time2 = time2.Zero;
            clock2.restart();

            switch(anwManSaved.model)
            {
                case modelPlane::Boeing787:
                {
                    anwManSaved.action == typeAction::Landing ? boeing.landing(window, bg, text) : boeing.takeoff(window, bg, text);
                    manager.chngStatusRunway(0);
                    boeing.updateVarParam();
                    break;
                }
                case modelPlane::CessnaCitation:
                {
                    anwManSaved.action == typeAction::Landing ? cessnaJet.landing(window, bg, text) : cessnaJet.takeoff(window, bg, text);
                    manager.chngStatusRunway(0);
                    cessnaJet.updateVarParam();
                    break;
                }
                case modelPlane::CirrusSR:
                {
                    anwManSaved.action == typeAction::Landing ? cirrusSR.landing(window, bg, text) : cirrusSR.takeoff(window, bg, text);
                    manager.chngStatusRunway(0);
                    cirrusSR.updateVarParam();
                    break;
                }

            }
                window->clear();
                window->draw(bg);
                window->draw(text);
                window->display();
        }

        if(time3.asSeconds() >= 10)
        {
            manager.update(window, bg, text);
            time3 = time3.Zero;
            clock3.restart();
        }

    }
    return 0;
};


mapping::mapping()
{
   this->titleWnd = TITLE;
   this->backgroundNameFile = BGFILENAME;
   this->sizeWnd.setMembers(LENGHTWND, WIDTHWND);
};

Sprite mapping::getSprite(int index)
{
    return this->elements.at(0);
};
