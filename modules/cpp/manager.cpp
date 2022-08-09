#include "../manager.h"
#include <math.h>
#include <type_traits>
#include <iostream>

using namespace std;

manager::manager(RenderWindow *window, Sprite background, Text &text)
{
    default_random_engine generator;
    generator.seed(time(0));
    uniform_int_distribution<int> distribution(1, 9);
    distribution(generator);
    String statusWeather = "Weather\n";    

    this->runwayBusy = false;
    this->windSpeed = distribution(generator);

    distribution = uniform_int_distribution<int>(1, 100);
    generator.seed(time(0));
    this->chanceRain = distribution(generator);

    distribution = uniform_int_distribution<int>(1, 100);
    generator.seed(time(0));
    this->chanceSnow = distribution(generator);

    int randNum = distribution(generator);

    if (randNum > chanceRain)
    {
        this->rain = (levelRain)(1.0 + 2.5 * ((float)chanceRain / 100.0));
    }
    else 
    {
        this->rain = levelRain::Nope;
    }

    randNum = distribution(generator);

    if(randNum > chanceSnow)
    {
        this->snow = 1;
    }
    else
    {
        this->snow = 0;
    }

    statusWeather += "Wind speed: " + to_string(this->windSpeed) + "\n" + "Level rain: "; 
    switch(this->rain)
    {
        case levelRain::Nope: statusWeather += "nope\n"; break;
        case levelRain::Light: statusWeather += "light\n"; break;
        case levelRain::Medium: statusWeather += "medium\n"; break;
        case levelRain::Heavy: statusWeather += "heavy\n"; break;
        default: break;
    }
    statusWeather += "Snow: ";
    switch((int)this->snow)
    {
        case 0: statusWeather += "no\n"; break;
        case 1: statusWeather += "yes\n"; break;
        default: break;
    }
    text.setString(statusWeather);

    window->clear();
    window->draw(background);
    window->draw(text);
    window->display();
};

anwManager manager::getResultManager(message<boeing_787> msg)
{
    anwManager answer;
    answer.model = modelPlane::Boeing787;

    if(msg.action == typeAction::Takeoff)
    {
        answer.action = typeAction::Takeoff;

        if(this->windSpeed >= 18.f && msg.plane.getPerLvlFuel() > 10)
        {
            answer.allowAct = 0;
            answer.solution = "Permission denied\nToo strong wind";
        }
        else if(this->runwayBusy == 1)
        {
            answer.allowAct = 0;
            answer.solution = "Permission denied\nRunway busy";
        }
        else
        {
            answer.allowAct = 1;
            this->runwayBusy = 1;
            answer.solution = "Permission granted";
        }
    }
    else
    {
        answer.action = typeAction::Landing;

        if(msg.plane.getAddWeight() > msg.plane.getMaxAddWeight())
        {
            answer.allowAct = 0;
            answer.solution = "Permission denied\nToo more additional weight";
        }
        else if(this->snow == 1)
        {
            answer.allowAct = 0;
            answer.solution = "Permission denied\nSnowing";
        }
        else if(windSpeed >= 18.f)
        {
            answer.allowAct = 0;
            answer.solution = "Permission denied\nToo strong wind";
        }
        else if(this->rain == levelRain::Heavy)
        {
            answer.allowAct = 0;
            answer.solution = "Permission denied\nToo strong rain";
        }
        else if(this->runwayBusy == 1)
        {
            answer.allowAct = 0;
            answer.solution = "Permission denied\nRunway busy";
        }
        else
        {
            answer.allowAct = 1;
            this->runwayBusy = 1;
            answer.solution = "Permission granted";
        }
    }
    cout << answer.solution << endl;
    cout << "------------------------------------" << endl << endl;
    return answer;
};

anwManager manager::getResultManager(message<cessnaM> msg)
{
    anwManager answer;
    answer.model = modelPlane::CessnaCitation;

    if(msg.action == typeAction::Takeoff)
    {
        answer.action = typeAction::Takeoff;

        if(this->windSpeed >= 12.f && msg.plane.getPerLvlFuel() > 10)
        {
            answer.allowAct = 0;
            answer.solution = "Permission denied\nToo strong wind";
        }
        else if(this->runwayBusy == 1)
        {
            answer.allowAct = 0;
            answer.solution = "Permission denied\nRunway busy";
        }
        else
        {
            answer.allowAct = 1;
            this->runwayBusy = 1;
            answer.solution = "Permission granted";
        }
    }
    else
    {
        answer.action = typeAction::Landing;

        if(msg.plane.getAddWeight() > msg.plane.getMaxAddWeight())
        {
            answer.allowAct = 0;
            answer.solution = "Permission denied\nToo more additional weight";
        }
        else if(this->snow == 1)
        {
            answer.allowAct = 0;
            answer.solution = "Permission denied\nSnowing";
        }
        else if(windSpeed >= 12.f)
        {
            answer.allowAct = 0;
            answer.solution = "Permission denied\nToo strong wind";
        }
        else if(this->rain == levelRain::Heavy)
        {
            answer.allowAct = 0;
            answer.solution = "Permission denied\nToo strong rain";
        }
        else if(this->rain == levelRain::Medium)
        {
            answer.allowAct = 0;
            answer.solution = "Permission denied\nToo strong rain";
        }
        else if(this->runwayBusy == 1)
        {
            answer.allowAct = 0;
            answer.solution = "Permission denied\nRunway busy";
        }
        else
        {
            answer.allowAct = 1;
            this->runwayBusy = 1;
            answer.solution = "Permission granted";
        }
    }
    cout << answer.solution << endl;
    cout << "------------------------------------" << endl << endl;

    return answer;
};

anwManager manager::getResultManager(message<cirrus> msg)
{
    anwManager answer;
    answer.model = modelPlane::CirrusSR;

    if(msg.action == typeAction::Takeoff)
    {
        answer.action = typeAction::Takeoff;

        if(this->windSpeed >= 9.f && msg.plane.getPerLvlFuel() > 10)
        {
            answer.allowAct = 0;
            answer.solution = "Permission denied\nToo strong wind";
        }
        else if(this->runwayBusy == 1)
        {
            answer.allowAct = 0;
            answer.solution = "Permission denied\nRunway busy";
        }
        else
        {
            answer.allowAct = 1;
            this->runwayBusy = 1;
            answer.solution = "Permission granted";
        }
    }
    else
    {
        answer.action = typeAction::Landing;

        if(msg.plane.getAddWeight() > msg.plane.getMaxAddWeight())
        {
            answer.allowAct = 0;
            answer.solution = "Permission denied\nToo more additional weight";
        }
        else if(this->snow == 1)
        {
            answer.allowAct = 0;
            answer.solution = "Permission denied\nSnowing";
        }
        else if(windSpeed >= 9.f)
        {
            answer.allowAct = 0;
            answer.solution = "Permission denied\nToo strong wind";
        }
        else if(this->rain == levelRain::Heavy)
        {
            answer.allowAct = 0;
            answer.solution = "Permission denied\nToo strong rain";
        }
        else if(this->rain == levelRain::Medium)
        {
            answer.allowAct = 0;
            answer.solution = "Permission denied\nToo strong rain";
        }
        else if(this->runwayBusy == 1)
        {
            answer.allowAct = 0;
            answer.solution = "Permission denied\nRunway busy";
        }
        else
        {
            answer.allowAct = 1;
            this->runwayBusy = 1;
            answer.solution = "Permission granted";
        }
    }
    cout << answer.solution << endl;
    cout << "------------------------------------" << endl << endl;

    return answer;
};

void manager::update(RenderWindow *window, Sprite background, Text &text)
{
    default_random_engine generator;
    generator.seed(time(0));
    uniform_int_distribution<int> distribution(-5, 5);
    distribution(generator);
    string statusWeather = "Weather\n";
    

    this->runwayBusy = false;
    this->windSpeed += distribution(generator);
    this->windSpeed = abs(this->windSpeed);

    distribution = uniform_int_distribution<int>(-10, 10);
    this->chanceRain += distribution(generator);
    this->chanceRain = abs(this->chanceRain);

    distribution = uniform_int_distribution<int>(-2, 2);
    this->chanceSnow += distribution(generator);
    this->chanceSnow = abs(this->chanceSnow);

    distribution = uniform_int_distribution<int>(1, 100);
    int randNum = distribution(generator);

    if (randNum > chanceRain)
    {
        this->rain = (levelRain)(1.0 + 2.5 * ((float)chanceRain / 100.0));
    }
    else 
    {
        this->rain = levelRain::Nope;
    }

    randNum = distribution(generator);

    if(randNum > chanceSnow)
    {
        this->snow = 1;
    }
    else
    {
        this->snow = 0;
    }

    statusWeather += "Wind speed: " + to_string(this->windSpeed) + "\n" + "Level rain: "; 
    switch(this->rain)
    {
        case levelRain::Nope: statusWeather += "nope\n"; break;
        case levelRain::Light: statusWeather += "light\n"; break;
        case levelRain::Medium: statusWeather += "medium\n"; break;
        case levelRain::Heavy: statusWeather += "heavy\n"; break;
        default: break;
    }
    statusWeather += "Snow: ";
    switch((int)this->snow)
    {
        case 0: statusWeather += "no\n"; break;
        case 1: statusWeather += "yes\n"; break;
        default: break;
    }
    text.setString(statusWeather);

    window->clear();
    window->draw(background);
    window->draw(text);
    window->display();
};

void manager::chngStatusRunway(bool status)
{
    this->runwayBusy = status;
};
