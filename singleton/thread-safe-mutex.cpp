#include <iostream>
#include <mutex>

class Singleton
{
private:
    Singleton() {};
    static Singleton *resource;
    static std::mutex mtx;

public:
    Singleton(const Singleton &cc) = delete;
    Singleton &operator=(const Singleton &rhs) = delete;

    Singleton(Singleton &&) = delete;
    Singleton &operator=(const Singleton &&dyingRhs) = delete;

    static Singleton *getInstance()
    {
        if (not resource)
        {
            std::lock_guard<std::mutex> lk(mtx);
            if (not resource)
            {
                resource = new Singleton();
            }
        }
        return resource;
    }

    void doSomething()
    {
        std::cout << "Singleton instance is doing something." << std::endl;
    }
};

Singleton *Singleton::resource = nullptr;
std::mutex Singleton::mtx;

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