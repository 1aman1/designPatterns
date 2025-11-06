#include <iostream>
#include <mutex>

class Singleton
{
private:
    Singleton() {};
    static Singleton *resource;
    static std::once_flag initFlag;
    static void init()
    {
        resource = new Singleton();
    }

public:
    Singleton(const Singleton &cc) = delete;
    Singleton &operator=(const Singleton &rhs) = delete;

    Singleton(Singleton &&) = delete;
    Singleton &operator=(const Singleton &&dyingRhs) = delete;

    static Singleton *getInstance()
    {
        std::call_once(initFlag, init);
        return resource;
    }

    void doSomething()
    {
        std::cout << "Singleton instance is doing something." << std::endl;
    }
};

Singleton *Singleton::resource = nullptr;
std::once_flag Singleton::initFlag;

int main()
{
    Singleton *singleton1 = Singleton::getInstance();
    singleton1->doSomething();

    Singleton *singleton2 = Singleton::getInstance();
    singleton2->doSomething();

    Singleton *singleton3 = std::move(Singleton::getInstance());
    singleton3->doSomething();

    std::cout << "Address of singleton3: " << singleton3 << std::endl;
    std::cout << "Address of singleton2: " << singleton2 << std::endl;
    std::cout << "Address of singleton1: " << singleton1 << std::endl;

    return 0;
}