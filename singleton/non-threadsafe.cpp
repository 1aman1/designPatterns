#include <iostream>
#include <thread>

using namespace std;

class Singleton
{
    std::string myString;

    Singleton(const std::string value) : myString(value) {}

    static Singleton *myInstance;

public:
    Singleton(const Singleton &cc) = delete;
    Singleton &operator=(const Singleton &) = delete;

    Singleton(Singleton &&mc) = delete;
    Singleton &operator=(Singleton &&) = delete;

    void SomeBusinessLogic()
    { /*....*/
    }

    static Singleton *GetInstance(const std::string &value);

    std::string getMessage() const { return myString; }
};

Singleton *Singleton::myInstance = nullptr;

Singleton *Singleton::GetInstance(const std::string &value)
{
    if (myInstance == nullptr)
    {
        myInstance = new Singleton(value);
    }

    return myInstance;
}

void ThreadFoo()
{
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton *singleton = Singleton::GetInstance("FOO");
    std::cout << singleton->getMessage() << "\n";
}

void ThreadBar()
{
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton *singleton = Singleton::GetInstance("BAR");
    std::cout << singleton->getMessage() << "\n";
}

int main()
{
    std::cout << "If you see the same value, then singleton was reused (yay!\n"
              << "If you see different values, then 2 singletons were created (booo!!)\n\n"
              << "RESULT:\n";

    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);
    t1.join();
    t2.join();

    return 0;
}