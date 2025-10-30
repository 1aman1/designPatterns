#ifndef OBSERVER_H
#define OBSERVER_H

// headers
// #include<string>

// interface
class Subscriber
{
    virtual void update(std::string message) = 0;
};

#endif // OBSERVER_H