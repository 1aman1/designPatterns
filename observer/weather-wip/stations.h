#ifndef STATIONS_H
#define STATIONS_H

// headers
#include "subject.h"

#include <Subscriber.h>
#include <list>

// concrete
class WeatherStation : public Subject
{
private:
    std::list<Subscriber *> subscribers;
    std::string weather;

public:
    WeatherStation() : weather("default"), subscribers({}) {}

    void addObserver(Subscriber *p_ob) override {};
    void removeObserver(Subscriber *p_ob) override {};
    void notifyObservers() override {};

    void weatherUpdate(std::string currentWeather);
};

#endif // STATIONS_H