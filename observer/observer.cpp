#include <iostream>
#include <vector>
#include <algorithm>

// observer
class IObserver
{
public:
    virtual void update(const std::string &message) = 0;
};

// subject
class ISubject
{
public:
    virtual void subscribe(IObserver *anObserver) = 0;
    virtual void unSubscribe(IObserver *anObserver) = 0;
    virtual void notify(const std::string &message) = 0;
};

// solid observer
class ConcreteObserver : public IObserver
{
    std::string observerName;

public:
    ConcreteObserver(const std::string &anObserverName) : observerName(anObserverName) {}

    void update(const std::string &message)
    {
        std::cout << "IObserver " << observerName << " received update: " << message << std::endl;
    }
};

// solid subject
class ConcreteSubject : public ISubject
{
    std::vector<IObserver *> listOfObservers;

public:
    void subscribe(IObserver *anObserver) override
    {
        listOfObservers.push_back(anObserver);
    }

    void unSubscribe(IObserver *anObserver) override
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
    ConcreteObserver observer1("IObserver 1");
    ConcreteObserver observer2("IObserver 2");

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
The IObserver class represents the IObserver interface, which defines the update method that specific observer classes implement.

The ISubject class represents the ISubject interface (Observable), which defines methods for attaching, detaching, and notifying observers.

The ConcreteSubject class is a concrete implementation of the ISubject interface. It maintains a list of observers and provides methods to manage the list. When the state changes, it notifies all registered observers.

The ConcreteObserver class is a concrete implementation of the IObserver interface. It defines the update method that gets called when the subject's state changes.

IN THE MAIN() FUNCTION, WE DEMONSTRATE THE USAGE OF THE OBSERVER PATTERN. WE CREATE A CONCRETESUBJECT OBJECT AND TWO CONCRETEOBSERVER OBJECTS. THE OBSERVERS ARE ATTACHED TO THE SUBJECT, AND WHEN THE SUBJECT'S STATE CHANGES (NOTIFIED WITH A VALUE), THE OBSERVERS RECEIVE THE UPDATES 
*/