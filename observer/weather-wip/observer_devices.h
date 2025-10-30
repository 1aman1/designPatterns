#ifndef OBSERVER_DEVICES_H
#define OBSERVER_DEVICES_H

// headers
#include "Subscriber.h"

class MobileDevice : public Subscriber
{
public:
    void update(std::string message) override {};
};

class LaptopDevice : public Subscriber
{
public:
    void update(std::string message) override {};
};

#endif