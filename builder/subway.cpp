#include <iostream>
#include <string>

// Product
class Subway
{
public:
    void setBread(const std::string &bread) { bread_ = bread; }
    void setSauce(const std::string &sauce) { sauce_ = sauce; }
    void setFilling(const std::string &filling) { filling_ = filling; }

    void showSub() const
    {
        std::cout << "Subway with Bread: " << bread_
                  << ", Sauce: " << sauce_
                  << ", Filling: " << filling_
                  << std::endl;
    }

private:
    std::string bread_;
    std::string sauce_;
    std::string filling_;
};

// Builder
class SubwayMaker
{
public:
    virtual ~SubwayMaker() {}
    virtual void breadMaker() = 0;
    virtual void sauceMaker() = 0;
    virtual void fillingMaker() = 0;
    virtual Subway *getMySub() = 0;
};

// Concrete Builder
class VeggieDeliteSubwayMaker : public SubwayMaker
{
public:
    VeggieDeliteSubwayMaker() { sub = new Subway(); }

    void breadMaker() override { sub->setBread("Honey Oat Parmesan"); }
    void sauceMaker() override { sub->setSauce("Mayo & Mint Sauce"); }
    void fillingMaker() override { sub->setFilling("Lettuce, Cucumber, Onion, Corn"); }

    Subway *getMySub() override { return sub; }

private:
    Subway *sub;
};

// Director
class SubwaySupervisor
{
public:
    void makeSubway(SubwayMaker *maker)
    {
        maker->breadMaker();
        maker->sauceMaker();
        maker->fillingMaker();
    }
};

int main()
{
    SubwaySupervisor supervisor;
    SubwayMaker *vegDeliteMaker = new VeggieDeliteSubwayMaker();

    supervisor.makeSubway(vegDeliteMaker);

    Subway *vegDelite = vegDeliteMaker->getMySub();
    vegDelite->showSub();

    delete vegDeliteMaker;
    delete vegDelite;

    return 0;
}
