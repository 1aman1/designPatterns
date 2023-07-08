#include <iostream>
#include <string>

// Product
class Subway
{
public:
    void setBread(const std::string &bread)
    {
        bread_ = bread;
    }

    void setSauce(const std::string &sauce)
    {
        sauce_ = sauce;
    }

    void setFilling(const std::string &filling)
    {
        filling_ = filling;
    }

    void showSub() const
    {
        std::cout << "Subway with Dough: " << bread_
                  << ", Sauce: " << sauce_
                  << ", Topping: " << filling_
                  << std::endl;
    }

private:
    std::string bread_;
    std::string sauce_;
    std::string filling_;
};

// Builder
class SubwayBuilder
{
public:
    virtual void buildBread() = 0;
    virtual void buildSauce() = 0;
    virtual void buildFilling() = 0;
    virtual Subway *getMySub() = 0;
};

// Concrete Builder 1
class VeggieDeliteSubwayBuilder : public SubwayBuilder
{
public:
    void buildBread() override
    {
        sub_->setBread("Honey Roast parmesan");
    }

    void buildSauce() override
    {
        sub_->setSauce("Mayo sauce / Mint sauce");
    }

    void buildFilling() override
    {
        sub_->setFilling("Lettuce, cucumber, onion, corn");
    }

    Subway *getMySub() override
    {
        return sub_;
    }

private:
    Subway *sub_ = new Subway();
};

// Director
class PizzaDirector
{
public:
    void makePizza(SubwayBuilder *builder)
    {
        builder->buildBread();
        builder->buildSauce();
        builder->buildFilling();
    }
};

int main()
{
    PizzaDirector director;

    SubwayBuilder *veggieDelightBuilder = new VeggieDeliteSubwayBuilder();
    director.makePizza(veggieDelightBuilder);
    Subway *veggieDelightSubway = veggieDelightBuilder->getMySub();
    veggieDelightSubway->showSub();

    delete veggieDelightBuilder;
    delete veggieDelightSubway;

    return 0;
}
