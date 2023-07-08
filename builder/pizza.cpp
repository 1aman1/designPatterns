#include <iostream>

using namespace std;
typedef string ingredient;

// Product
class Pizza
{
public:
    void setDough(const ingredient &aDough)
    {
        dough_ = aDough;
    }

    void setSauce(const ingredient &aSauce)
    {
        sauce_ = aSauce;
    }

    void setTopping(const ingredient &aTopping)
    {
        topping_ = aTopping;
    }

    void showPizza()
    {
        std::cout << "Pizza with Dough: " << dough_
                  << ", Sauce: " << sauce_
                  << ", Topping: " << topping_
                  << std::endl;
    }

private:
    ingredient dough_;
    ingredient sauce_;
    ingredient topping_;
};

// Builder
class IPizzaBuilder
{
public:
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
    virtual Pizza *getPizza() = 0;
};

// Concrete Builder 1
class FarmhousePizzaBuilder : public IPizzaBuilder
{
public:
    void buildDough() override
    {
        pizza_->setDough("Thin Crust");
    }

    void buildSauce() override
    {
        pizza_->setSauce("Mayo");
    }

    void buildTopping() override
    {
        pizza_->setTopping("Mozzarella cheese");
    }

    Pizza *getPizza() override
    {
        return pizza_;
    }

private:
    Pizza *pizza_ = new Pizza();
};

// Concrete Builder 2
class TandooriPaneerPizzaBuilder : public IPizzaBuilder
{
public:
    void buildDough() override
    {
        pizza_->setDough("Cheese Burst");
    }

    void buildSauce() override
    {
        pizza_->setSauce("Tomato sauce");
    };

    void buildTopping() override
    {
        pizza_->setTopping("Jalapeno, Onions, Paneer");
    }

    Pizza *getPizza()
    {
        return pizza_;
    };

private:
    Pizza *pizza_ = new Pizza();
};

// Director
class PizzaDirector
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
    PizzaDirector director;

    IPizzaBuilder *FarmhouseBuilder = new FarmhousePizzaBuilder();
    director.buildPizza(FarmhouseBuilder);
    Pizza *FarmhousePizza = FarmhouseBuilder->getPizza();
    FarmhousePizza->showPizza();

    IPizzaBuilder *TandooriPaneerBuilder = new TandooriPaneerPizzaBuilder();
    director.buildPizza(TandooriPaneerBuilder);
    Pizza *TandooriPaneer = TandooriPaneerBuilder->getPizza();
    TandooriPaneer->showPizza();

    return 0;
}

/* 
The Pizza class represents the product being built. It has methods to set various attributes and a method to display the details of the pizza.

The PizzaBuilder class declares the interface for building the parts of the Pizza object. It defines pure virtual methods for building the dough, sauce, topping, and retrieving the constructed pizza.

The TandooriPaneerBuilder and FarmhousePizzaBuilder are concrete implementations of the PizzaBuilder interface. They provide specific implementations for building the parts of the pizza.

The PizzaDirector class controls the construction process. It has a method makePizza() that takes a PizzaBuilder as input and invokes the appropriate methods to build the pizza. 

THE BUILDER DESIGN PATTERN ALLOWS FLEXIBILITY IN CREATING OBJECTS WITH DIFFERENT CONFIGURATIONS WHILE KEEPING THE CONSTRUCTION PROCESS SEPARATE FROM THE PRODUCT ITSELF. IT PROMOTES THE SINGLE RESPONSIBILITY PRINCIPLE AND HELPS AVOID LARGE AND COMPLEX CONSTRUCTORS.
*/