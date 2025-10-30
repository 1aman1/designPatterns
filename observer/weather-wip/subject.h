#ifndef SUBJECT_H
#define SUBJECT_H

#include "Subscriber.h"

// interface
class Subject
{
    virtual void addObserver(Subscriber *p_ob) = 0;
    virtual void removeObserver(Subscriber *p_ob) = 0;
    virtual void notifyObservers() = 0;
};

#endif