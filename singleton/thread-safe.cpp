#include <iostream>
#include <mutex>

class Singleton
{
private:
    static Singleton *instance;
    static std::mutex mutex;

    Singleton() {}

public:
    Singleton(const Singleton &) = delete;

    Singleton(Singleton &&) = delete;

    Singleton &operator=(const Singleton &) = delete;

    static Singleton *getInstance()
    {
        if (instance == nullptr)
        {
            std::lock_guard<std::mutex> lock(mutex);
            if (instance == nullptr)
            {
                instance = new Singleton();
            }
        }
        return instance;
    }

    void doSomething()
    {
        std::cout << "Singleton instance is doing something." << std::endl;
    }
};

Singleton *Singleton::instance = nullptr;
std::mutex Singleton::mutex;

int main()
{
    Singleton *singleton1 = Singleton::getInstance();
    singleton1->doSomething();

    Singleton *singleton2 = Singleton::getInstance();
    singleton2->doSomething();

    // The addresses of singleton1 and singleton2 should be the same
    std::cout << "Address of singleton1: " << singleton1 << std::endl;
    std::cout << "Address of singleton2: " << singleton2 << std::endl;

    return 0;
}