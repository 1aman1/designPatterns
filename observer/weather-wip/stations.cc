#include "stations.h"

void WeatherStation::addObserver(Subscriber *p_ob)
{
    subscribers.push_back(p_ob);
}

void WeatherStation::removeObserver(Subscriber *p_ob)
{
    subscribers.remove(p_ob);
}

void WeatherStation::notifyObservers()
{
    for_each(begin(subscribers), end(subscribers), [](subscriber)
             { subscriber->update(); });
}

void WeatherStation::weatherUpdate(std::string currentWeather)
{
    weather = currentWeather;
    notifyObservers();
}