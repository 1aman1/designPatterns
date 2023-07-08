#include <iostream>
#include <vector>
#include <algorithm>

// observer
class Observer
{
public:
    virtual void update(const std::string &message) = 0;
};

// some subject
class Subject
{
public:
    virtual void subscribe(Observer *anObserver) = 0;
    virtual void unSubscribe(Observer *anObserver) = 0;
    virtual void notify(const std::string &message) = 0;
};

// solid observer
class ConcreteObserver : public Observer
{
    std::string observerName;

public:
    ConcreteObserver(const std::string &anObserverName) : observerName(anObserverName) {}

    void update(const std::string &message)
    {
        std::cout << "Observer " << observerName << " received update: " << message << std::endl;
    }
};

// solid subject
class ConcreteSubject : public Subject
{
    std::vector<Observer *> listOfObservers;

public:
    void subscribe(Observer *anObserver) override
    {
        listOfObservers.push_back(anObserver);
    }

    void unSubscribe(Observer *anObserver) override
    {
        listOfObservers.erase(std::remove(listOfObservers.begin(), listOfObservers.end(), anObserver), listOfObservers.end());
    }

    void notify(const std::string &message) override
    {
        for (auto observer : listOfObservers)
        {
            observer->update(message);
        }
    }
};

int main()
{
    // subject
    ConcreteSubject subject;

    // observer
    ConcreteObserver observer1("Observer 1");
    ConcreteObserver observer2("Observer 2");

    // subsribe
    subject.subscribe(&observer1);
    subject.subscribe(&observer2);

    // notify
    subject.notify("low supply");

    // ubsubscribe
    subject.unSubscribe(&observer1);
    subject.notify("even supply");

    return 0;
}
/* 
The Observer class represents the Observer interface, which defines the update method that specific observer classes implement.

The Subject class represents the Subject interface (Observable), which defines methods for attaching, detaching, and notifying observers.

The ConcreteSubject class is a concrete implementation of the Subject interface. It maintains a list of observers and provides methods to manage the list. When the state changes, it notifies all registered observers.

The ConcreteObserver class is a concrete implementation of the Observer interface. It defines the update method that gets called when the subject's state changes.

IN THE MAIN() FUNCTION, WE DEMONSTRATE THE USAGE OF THE OBSERVER PATTERN. WE CREATE A CONCRETESUBJECT OBJECT AND TWO CONCRETEOBSERVER OBJECTS. THE OBSERVERS ARE ATTACHED TO THE SUBJECT, AND WHEN THE SUBJECT'S STATE CHANGES (NOTIFIED WITH A VALUE), THE OBSERVERS RECEIVE THE UPDATES 
*/