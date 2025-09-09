#include <iostream>

using namespace std;
typedef string ingredient;

class Pizza
{
public:
    void setDough(ingredient dough) { dough_ = dough; }
    void setSauce(ingredient sauce) { sauce_ = sauce; }
    void setTopping(ingredient topping) { topping_ = topping; }
    void showPizza()
    {
        std::cout << "Pizza Ready!! (ingredients//"
                  << "Dough: " << dough_
                  << ", Sauce: " << sauce_
                  << ", Topping: " << topping_
                  << ")" << std::endl;
    }

private:
    ingredient dough_;
    ingredient sauce_;
    ingredient topping_;
};

class IPizzaBuilder
{
public:
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
    virtual Pizza *getPizza() = 0;
};

class RegularPizzaBuilder : public IPizzaBuilder
{
public:
    void buildDough() override { pizza_->setDough("Regular dough"); }
    void buildSauce() override { pizza_->setSauce("Tomato sauce"); }
    void buildTopping() override { pizza_->setTopping("Mozzarella cheese"); }
    Pizza *getPizza() override { return pizza_; }

private:
    Pizza *pizza_ = new Pizza();
};

class SpicyPizzaBuilder : public IPizzaBuilder
{
public:
    void buildDough() override { pizza_->setDough("Spicy dough"); }
    void buildSauce() override { pizza_->setSauce("Hot sauce"); }
    void buildTopping() override { pizza_->setTopping("Spicy pepperoni"); }
    Pizza *getPizza() override { return pizza_; }

private:
    Pizza *pizza_ = new Pizza();
};

class PizzaSupervisor
{
public:
    void buildPizza(IPizzaBuilder *builder)
    {
        builder->buildDough();
        builder->buildSauce();
        builder->buildTopping();
    }
};

int main()
{
    PizzaSupervisor supervisor;

    RegularPizzaBuilder *type1Builder = new RegularPizzaBuilder();
    supervisor.buildPizza(type1Builder);
    Pizza *pizza1 = type1Builder->getPizza();
    pizza1->showPizza();

    SpicyPizzaBuilder *type2Builder = new SpicyPizzaBuilder();
    supervisor.buildPizza(type2Builder);
    Pizza *pizza2 = type2Builder->getPizza();
    pizza2->showPizza();

    delete type1Builder;
    delete pizza1;
    delete type2Builder;
    delete pizza2;

    return 0;
}
