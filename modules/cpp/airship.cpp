#include "../airship.h"
#include <random>



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

int boeing_787::takeoff(RenderWindow *window, Sprite background, Text text)
{
    ClearPolEvent(window);
    this->sprite.setPosition(-300, 550);
    window->clear();
    window->draw(background);
    window->draw(text);
    window->draw(this->sprite);
    window->display();

    for(int i = 1; i <= 600; i++)
    {
        ClearPolEvent(window);
        this->sprite.move(1.0f, 0.09f);
        window->clear();
        window->draw(background);
        window->draw(text);
        window->draw(this->sprite);
        window->display();
    }


    float kfSpeed = 1.f;
    for(int i = 1; i <= 1900; i++)
    {
        ClearPolEvent(window);
        this->sprite.move(1.0f * kfSpeed, 0.f);
        window->clear();
        window->draw(background);
        window->draw(text);
        window->draw(this->sprite);
        window->display();
        kfSpeed *= 0.99892f;
    }

    for(int i = 1; i <= 300; i++)
    {
        ClearPolEvent(window);
        window->clear();
        window->draw(background);
        window->draw(text);
        window->draw(this->sprite);
        window->display();
    }

    this->updateVarParam();

    return 0;
};

int cessnaM::takeoff(RenderWindow *window, Sprite background, Text text)
{
    ClearPolEvent(window);
    this->sprite.setPosition(-350, 580);
    window->clear();
    window->draw(background);
    window->draw(text);
    window->draw(this->sprite);
    window->display();

    for(int i = 1; i <= 600; i++)
    {
        ClearPolEvent(window);
        this->sprite.move(1.f, 0.15f);
        window->clear();
        window->draw(background);
        window->draw(text);
        window->draw(this->sprite);
        window->display();
    }

    float kfSpeed = 1.f;
    for(int i = 1; i <= 2000; i++)
    {
        ClearPolEvent(window);
        this->sprite.move(0.9f * kfSpeed, 0.f);
        window->clear();
        window->draw(background);
        window->draw(text);
        window->draw(this->sprite);
        window->display();
        kfSpeed *= 0.99892f;
    }

    for(int i = 1; i <= 300; i++)
    {
        ClearPolEvent(window);
        window->clear();
        window->draw(background);
        window->draw(text);
        window->draw(this->sprite);
        window->display();
    }

    this->updateVarParam();

    return 0;
};

int cirrus::takeoff(RenderWindow *window, Sprite background, Text text)
{
    ClearPolEvent(window);
    this->sprite.setPosition(-350, 640);
    window->clear();
    window->draw(background);
    window->draw(text);
    window->draw(this->sprite);
    window->display();

    for(int i = 1; i <= 800; i++)
    {
        ClearPolEvent(window);
        this->sprite.move(1.f, 0.1f);
        window->clear();
        window->draw(background);
        window->draw(text);
        window->draw(this->sprite);
        window->display();
    }

    float kfSpeed = 1.f;
    for(int i = 1; i <= 2000; i++)
    {
        ClearPolEvent(window);
        this->sprite.move(0.9f * kfSpeed, 0.f);
        window->clear();
        window->draw(background);
        window->draw(this->sprite);
        window->draw(text);
        window->display();
        kfSpeed *= 0.99892f;
    }

    for(int i = 1; i <= 300; i++)
    {
        ClearPolEvent(window);
        window->clear();
        window->draw(background);
        window->draw(this->sprite);
        window->draw(text);
        window->display();
    }

    this->updateVarParam();

    return 0;
};

int boeing_787::landing(RenderWindow *window, Sprite background, Text text)
{
    ClearPolEvent(window);
    this->sprite.setPosition(0, 610);
    window->clear();
    window->draw(background);
    window->draw(text);
    window->draw(this->sprite);
    window->display();

    for(int i = 1; i <= 150; i++)
    {
        ClearPolEvent(window);
        window->clear();
        window->draw(background);
        window->draw(text);
        window->draw(this->sprite);
        window->display();
    }

    float kfSpeed = 1.f;
    for(int i = 1; i <= 1600; i++)
    {
        ClearPolEvent(window);
        this->sprite.move(0.2f * kfSpeed, 0.f);
        window->clear();
        window->draw(background);
        window->draw(text);
        window->draw(this->sprite);
        window->display();
        kfSpeed *= 1.001f;
    }

    for(int i = 1; i <= 800; i++)
    {
        ClearPolEvent(window);
        kfSpeed *= 1.0008f;
        this->sprite.move(0.23f * kfSpeed, -0.07f);
        window->clear();
        window->draw(background);
        window->draw(text);
        window->draw(this->sprite);
        window->display();
    }

    this->updateVarParam();

    return 0;
};


int cessnaM::landing(RenderWindow *window, Sprite background, Text text)
{
    ClearPolEvent(window);
    this->sprite.setPosition(0, 670);
    window->clear();
    window->draw(background);
    window->draw(text);
    window->draw(this->sprite);
    window->display();

    for(int i = 1; i <= 150; i++)
    {
        ClearPolEvent(window);
        window->clear();
        window->draw(background);
        window->draw(text);
        window->draw(this->sprite);
        window->display();
    }

    float kfSpeed = 1.f;
    for(int i = 1; i <= 1600; i++)
    {
        ClearPolEvent(window);
        this->sprite.move(0.2f * kfSpeed, 0.f);
        window->clear();
        window->draw(background);
        window->draw(text);
        window->draw(this->sprite);
        window->display();
        kfSpeed *= 1.001f;
    }

    for(int i = 1; i <= 800; i++)
    {
        ClearPolEvent(window);
        kfSpeed *= 1.0001f;
        this->sprite.move(0.25f * kfSpeed, -0.07f);
        window->clear();
        window->draw(background);
        window->draw(text);
        window->draw(this->sprite);
        window->display();
    }

    this->updateVarParam();

    return 0;
};

int cirrus::landing(RenderWindow *window, Sprite background, Text text)
{
    this->sprite.setPosition(0, 720);
    window->clear();
    window->draw(background);
    window->draw(text);
    window->draw(this->sprite);
    window->display();

    for(int i = 1; i <= 150; i++)
    {
        ClearPolEvent(window);
        window->clear();
        window->draw(background);
        window->draw(text);
        window->draw(this->sprite);
        window->display();
    }

    float kfSpeed = 1.f;
    for(int i = 1; i <= 2000; i++)
    {
        ClearPolEvent(window);
        this->sprite.move(0.11f * kfSpeed, 0.f);
        window->clear();
        window->draw(background);
        window->draw(text);
        window->draw(this->sprite);
        window->display();
        kfSpeed *= 1.001f;
    }

    for(int i = 1; i <= 1300; i++)
    {
        ClearPolEvent(window);
        kfSpeed *= 1.00001f;
        this->sprite.move(0.11f * kfSpeed, -0.05f);
        window->clear();
        window->draw(background);
        window->draw(text);
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
