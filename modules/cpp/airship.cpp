#include "../airship.h"

void ClearPolEvent(RenderWindow *window)
{
    Event event;

    while(window->pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            window->close();
        }
    }
};

boeing_787::boeing_787()
{
    this->name = "Boeing 787";
    this->weight = 115300;
    this->index = 1;
    this->maxAddWeight = 192800;
    this->tankVolume = 126200;


    default_random_engine generator;
    generator.seed(time(0));
    uniform_int_distribution<int> distribution(1, this->tankVolume);
    distribution(generator);

    this->currentLvlFuel = distribution(generator);

    distribution = uniform_int_distribution<int>(1, this->maxAddWeight + 50000);

    this->addWeight = distribution(generator);
};

boeing_787::boeing_787(Sprite sprite, Texture texture, int index)
{
    this->name = "Boeing 787";
    this->sprite = sprite;
    this->weight = 115300;
    this->maxAddWeight = 192800;
    this->index = index;
    this->texture = texture;
    this->tankVolume = 126200;


    default_random_engine generator;
    generator.seed(time(0));
    uniform_int_distribution<int> distribution(1, this->tankVolume);
    distribution(generator);

    this->currentLvlFuel = distribution(generator);
    distribution = uniform_int_distribution<int>(1, this->maxAddWeight + 50000);

    this->addWeight = distribution(generator);

    this->sprite.setTexture(this->texture);
};

cessnaM::cessnaM()
{
    this->name = "Cessna Citation";
    this->weight = 15195;
    this->maxAddWeight = 9155;
    this->index = 2;
    this->tankVolume = 7291;


    default_random_engine generator;
    generator.seed(time(0));
    uniform_int_distribution<int> distribution(1, this->tankVolume);
    distribution(generator);

    this->currentLvlFuel = distribution(generator);
    
    distribution = uniform_int_distribution<int>(1, this->maxAddWeight + 3000);

    this->addWeight = distribution(generator);
};

cessnaM::cessnaM(Sprite sprite, Texture texture, int index)
{
    this->name = "Cessna Citation";
    this->sprite = sprite;
    this->weight = 15195;
    this->maxAddWeight = 9155;
    this->index = index;
    this->texture = texture;
    this->tankVolume = 7291;


    default_random_engine generator;
    generator.seed(time(0));
    uniform_int_distribution<int> distribution(1, this->tankVolume);
    distribution(generator);

    this->currentLvlFuel = distribution(generator);

    distribution = uniform_int_distribution<int>(1, this->maxAddWeight + 3000);

    this->addWeight = distribution(generator);

    this->sprite.setTexture(this->texture);
};

cirrus::cirrus()
{
    this->name = "Cirrus SR";
    this->weight = 965;
    this->maxAddWeight = 400;
    this->index = 3;
    this->tankVolume = 230;


    default_random_engine generator;
    generator.seed(time(0));
    uniform_int_distribution<int> distribution(1, this->tankVolume);
    distribution(generator);

    this->currentLvlFuel = distribution(generator);

    distribution = uniform_int_distribution<int>(1, this->maxAddWeight + 100);

    this->addWeight = distribution(generator);
};

cirrus::cirrus(Sprite sprite, Texture texture, int index)
{
    this->name = "Cirrus SR";
    this->weight = 965;
    this->maxAddWeight = 400;
    this->sprite = sprite;
    this->texture = texture;
    this->index = index;
    this->tankVolume = 230;


    default_random_engine generator;
    generator.seed(time(0));
    uniform_int_distribution<int> distribution(1, this->tankVolume);
    distribution(generator);

    this->currentLvlFuel = distribution(generator);

    distribution = uniform_int_distribution<int>(1, this->maxAddWeight + 100);

    this->addWeight = distribution(generator);

    this->sprite.setTexture(this->texture);
};

int boeing_787::landing(RenderWindow *window, visibleElm elms)
{
    elms.reload(window);
    this->sprite.setPosition(-300, 550);
    window->draw(this->sprite);
    window->display();

    for(int i = 1; i <= 600; i++)
    {
        this->sprite.move(1.0f, 0.09f);
        elms.reload(window);
        window->draw(this->sprite);
        window->display();
    }


    float kfSpeed = 1.f;
    for(int i = 1; i <= 1900; i++)
    {
        this->sprite.move(1.0f * kfSpeed, 0.f);
        elms.reload(window);
        window->draw(this->sprite);
        window->display();
        kfSpeed *= 0.99892f;
    }

    for(int i = 1; i <= 300; i++)
    {
        elms.reload(window);
        window->draw(this->sprite);
        window->display();
    }

    this->updateVarParam();

    return 0;
};

int cessnaM::landing(RenderWindow *window, visibleElm elms)
{
    this->sprite.setPosition(-350, 580);
    elms.reload(window);
    window->draw(this->sprite);
    window->display();

    for(int i = 1; i <= 600; i++)
    {
        this->sprite.move(1.f, 0.15f);
        elms.reload(window);
        window->draw(this->sprite);
        window->display();
    }

    float kfSpeed = 1.f;
    for(int i = 1; i <= 2000; i++)
    {
        this->sprite.move(0.9f * kfSpeed, 0.f);
        elms.reload(window);
        window->draw(this->sprite);
        window->display();
        kfSpeed *= 0.99892f;
    }

    for(int i = 1; i <= 300; i++)
    {
        elms.reload(window);
        window->draw(this->sprite);
        window->display();
    }

    this->updateVarParam();

    return 0;
};

int cirrus::landing(RenderWindow *window, visibleElm elms)
{
    this->sprite.setPosition(-350, 640);
    elms.reload(window);
    window->draw(this->sprite);
    window->display();

    for(int i = 1; i <= 800; i++)
    {
        this->sprite.move(1.f, 0.1f);
        elms.reload(window);
        window->draw(this->sprite);
        window->display();
    }

    float kfSpeed = 1.f;
    for(int i = 1; i <= 2000; i++)
    {
        this->sprite.move(0.9f * kfSpeed, 0.f);
        elms.reload(window);
        window->draw(this->sprite);
        window->display();
        kfSpeed *= 0.99892f;
    }

    for(int i = 1; i <= 300; i++)
    {
        elms.reload(window);
        window->draw(this->sprite);
        window->display();
    }

    this->updateVarParam();

    return 0;
};

int boeing_787::takeoff(RenderWindow *window, visibleElm elms)
{
    this->sprite.setPosition(0, 610);
    elms.reload(window);
    window->draw(this->sprite);
    window->display();

    for(int i = 1; i <= 150; i++)
    {
        elms.reload(window);
        window->draw(this->sprite);
        window->display();
    }

    float kfSpeed = 1.f;
    for(int i = 1; i <= 1600; i++)
    {
        this->sprite.move(0.2f * kfSpeed, 0.f);
        elms.reload(window);
        window->draw(this->sprite);
        window->display();
        kfSpeed *= 1.001f;
    }

    for(int i = 1; i <= 800; i++)
    {
        kfSpeed *= 1.0008f;
        this->sprite.move(0.23f * kfSpeed, -0.07f);
        elms.reload(window);
        window->draw(this->sprite);
        window->display();
    }

    this->updateVarParam();

    return 0;
};


int cessnaM::takeoff(RenderWindow *window, visibleElm elms)
{
    this->sprite.setPosition(0, 670);
    elms.reload(window);
    window->draw(this->sprite);
    window->display();

    for(int i = 1; i <= 150; i++)
    {
        elms.reload(window);
        window->draw(this->sprite);
        window->display();
    }

    float kfSpeed = 1.f;
    for(int i = 1; i <= 1600; i++)
    {
        this->sprite.move(0.2f * kfSpeed, 0.f);
        elms.reload(window);
        window->draw(this->sprite);
        window->display();
        kfSpeed *= 1.001f;
    }

    for(int i = 1; i <= 800; i++)
    {
        kfSpeed *= 1.0001f;
        this->sprite.move(0.25f * kfSpeed, -0.07f);
        elms.reload(window);
        window->draw(this->sprite);
        window->display();
    }

    this->updateVarParam();

    return 0;
};

int cirrus::takeoff(RenderWindow *window, visibleElm elms)
{
    this->sprite.setPosition(0, 720);
    elms.reload(window);
    window->draw(this->sprite);
    window->display();

    for(int i = 1; i <= 150; i++)
    {
        elms.reload(window);
        window->draw(this->sprite);
        window->display();
    }

    float kfSpeed = 1.f;
    for(int i = 1; i <= 2000; i++)
    {
        this->sprite.move(0.11f * kfSpeed, 0.f);
        elms.reload(window);
        window->draw(this->sprite);
        window->display();
        kfSpeed *= 1.001f;
    }

    for(int i = 1; i <= 1300; i++)
    {
        kfSpeed *= 1.00001f;
        this->sprite.move(0.11f * kfSpeed, -0.05f);
        elms.reload(window);
        window->draw(this->sprite);
        window->display();
    }

    this->updateVarParam();

    return 0;
};

void airship::setSprite(Sprite sprite)
{
    this->sprite = sprite;
};

Sprite airship::getSprite()
{
    return this->sprite;
};

void airship::setIndex(int index)
{
    this->index = index;
};

int airship::getIndex()
{
    return this->index;
};

string airship::getName()
{
    return this->name;
};

int airship::getAddWeight()
{
    return this->addWeight;
};

int airship::getPerLvlFuel()
{
    return this->currentLvlFuel / (this->tankVolume / 100);  
};

int airship::getMaxAddWeight()
{
    return this->maxAddWeight;
};

void airship::updateVarParam()
{

    default_random_engine generator;
    generator.seed(time(0));
    uniform_int_distribution<int> distribution(1, this->tankVolume);
    distribution(generator);

    this->currentLvlFuel = distribution(generator);

    if (this->name == "Boeing 787")
    {
        distribution = uniform_int_distribution<int>(1, this->maxAddWeight + 50000);
    }

    if (this->name == "Cessna Citation")
    {
        distribution = uniform_int_distribution<int>(1, this->maxAddWeight + 3000);
    }

    if (this->name == "Cirrus SR")
    {
        distribution = uniform_int_distribution<int>(1, this->maxAddWeight + 100);
    }

    this->addWeight = distribution(generator);
};

message<boeing_787> boeing_787::generateMsg()
{

    default_random_engine generator;
    generator.seed(time(0));
    uniform_int_distribution<int> distribution(1, 50);
    distribution(generator);

    message<boeing_787> msg;
    string typeAction = distribution(generator) % 2 == 0 ? "takeoff" : "landing";
    string strMessage = "Request on " + typeAction + "\n" + "Airship model: " + this->name + "\n";

    if (typeAction == "landing")
    {
         strMessage += "Level fuel in percent: " + to_string(this->getPerLvlFuel()) + "%\n";
         msg.action = typeAction::Landing;
    }
    else
    {
        strMessage += "Additional weight = " + to_string(this->addWeight) + " is "
            + to_string(this->maxAddWeight) + "\n"; 
        msg.action = typeAction::Takeoff;
}

    msg.generateMsg = strMessage;
    msg.plane = *this;

    cout << msg.generateMsg;
    return msg;

}

message<cessnaM> cessnaM::generateMsg()
{

    default_random_engine generator;
    generator.seed(time(0));
    uniform_int_distribution<int> distribution(1, 50);
    distribution(generator);

    message<cessnaM> msg;
    string typeAction = distribution(generator) % 2 == 0 ? "takeoff" : "landing";
    string strMessage = "Request on " + typeAction + "\n" + "Airship model: " + this->name + "\n";

    if (typeAction == "landing")
    {
         strMessage += "Level fuel in percent: " + to_string(this->getPerLvlFuel()) + "%\n";
         msg.action = typeAction::Landing;
    }
    else
    {
        strMessage += "Additional weight = " + to_string(this->addWeight) + " is "
            + to_string(this->maxAddWeight) + "\n"; 
        msg.action = typeAction::Takeoff;
}

    msg.generateMsg = strMessage;
    msg.plane = *this;

    cout << msg.generateMsg;
    return msg;

}

message<cirrus> cirrus::generateMsg()
{

    default_random_engine generator;
    generator.seed(time(0));
    uniform_int_distribution<int> distribution(1, 50);
    distribution(generator);

    message<cirrus> msg;
    string typeAction = distribution(generator) % 2 == 0 ? "takeoff" : "landing";
    string strMessage = "Request on " + typeAction + "\n" + "Airship model: " + this->name + "\n";

    if (typeAction == "landing")
    {
         strMessage += "Level fuel in percent: " + to_string(this->getPerLvlFuel()) + "%\n";
         msg.action = typeAction::Landing;
    }
    else
    {
        strMessage += "Additional weight = " + to_string(this->addWeight) + " is "
            + to_string(this->maxAddWeight) + "\n"; 
        msg.action = typeAction::Takeoff;
    }

    msg.generateMsg = strMessage;
    msg.plane = *this;

    cout << msg.generateMsg;
    return msg;
};

visibleElm::visibleElm()
{
    this->stackSprite = new Sprite[10];
    this->stackText = new Text[10];
    this->currIndxSprite = -1;
    this->currIndxTexture = -1;
};

void visibleElm::add(Sprite& sprite)
{
    if(this->currIndxSprite < 9)
    {
        this->stackSprite[++this->currIndxSprite] = sprite;
    }
};

void visibleElm::add(Text& text)
{
    if(this->currIndxTexture < 9)
    {
        this->stackText[++this->currIndxTexture] = text;
    }
};

void visibleElm::reload(RenderWindow *window)
{
    ClearPolEvent(window);
    window->clear();  

    for(int i = this->currIndxSprite; i >= 0; i--)
    {
        window->draw(this->stackSprite[i]);
    }

    for(int i = this->currIndxTexture; i >= 0; i--)
    {
        window->draw(this->stackText[i]);
    }
    ClearPolEvent(window);
};

