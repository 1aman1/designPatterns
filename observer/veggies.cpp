#include <iostream>
#include <vector>
#include <algorithm>

// observer
class Observer_I
{
public:
    virtual void update(const std::string &message) = 0;
};

// some subject
class Subject_I
{
public:
    virtual void subscribe(Observer *anObserver) = 0;
    virtual void unSubscribe(Observer *anObserver) = 0;
    virtual void notify(const std::string &message) = 0;
};

// solid observer
class ConcreteObserver : public Observer_I
{
    std::string observerName;

ublic:
    ConcreteObserver(const std::string &anObserverName) : observerName(anObserverName) {}

    void update(const std::string &message)
    {
        std::cout << observerName << " received update: " << message << std::endl;
    }
};

// solid subject
class ConcreteSubject : public Subject_I
{
    std::vector<Observer_I *> listOfObservers;

public:
    void subscribe(Observer_I *anObserver) override
    {
        listOfObservers.push_back(anObserver);
    }

    void unSubscribe(Observer_I *anObserver) override
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
    ConcreteObserver observer1("Dominos");
    ConcreteObserver observer2("Pizza Hut");

    // subsribe
    subject.subscribe(&observer1);
    subject.subscribe(&observer2);

    // notify
    subject.notify("low oregano supply");

    // ubsubscribe // found another source for oregano
    subject.unSubscribe(&observer1);
    subject.notify("back to even oregano supply");

    return 0;
}
