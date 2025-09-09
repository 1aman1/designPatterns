#include <iostream>
#include <vector>
#include <algorithm>

// observer
class IObserver
{
public:
    virtual void update(const std::string &message) = 0;
    virtual std::string getObserverName() const = 0; 
};

// some subject
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

    void update(const std::string &message) override
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
	std::cout << anObserver->getObserverName() << " subscribed\n";
    }

    void unSubscribe(IObserver *anObserver) override
    {
        listOfObservers.erase(std::remove(listOfObservers.begin(), listOfObservers.end(), anObserver), listOfObservers.end());
        std::cout << anObserver->getObserverName() << " unsubscribed\n";	
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
