#include <iostream>
using namespace std;

class Singleton
{

protected:
    Singleton(const std::string value) : var(value) {}

    static Singleton *singleton_;

    std::string var;

public:
    Singleton(Singleton &other) = delete;

    void operator=(const Singleton &) = delete;

    static Singleton *GetInstance(const std::string &value);

    void SomeBusinessLogic()
    {
        // ...
    }

    std::string value() const
    {
        return var;
    }
};

Singleton *Singleton::singleton_ = nullptr;

Singleton *Singleton::GetInstance(const std::string &value)
{
    if (singleton_ == nullptr)
    {
        singleton_ = new Singleton(value);
    }
    return singleton_;
}

int main()
{
    std::cout << "If you see the same value, then singleton was reused (yay!\n"
              << "If you see different values, then 2 singletons were created (booo!!)\n\n"
              << "RESULT:\n";

    Singleton *singleton_1 = Singleton::GetInstance("FOO");
    std::cout << singleton_1->value() << "\n";

    Singleton *singleton_2 = Singleton::GetInstance("BAR");
    std::cout << singleton_2->value() << "\n";

    return 0;
}