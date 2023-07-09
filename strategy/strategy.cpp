#include <iostream>

// strategy contract

class IStrategy
{
public:
    virtual void sort() = 0;
};

// concrete strategies
class BubbleSort : public IStrategy
{
public:
    void sort() override
    {
        std::cout << "BubbleSort\n";
    }
};

class MergeSort : public IStrategy
{
public:
    void sort() override
    {
        std::cout << "MergeSort\n";
    }
};

// context / user
class SorterMerchant
{
    IStrategy *strategy;

public:
    void setStrategy(IStrategy *aStrategy)
    {
        this->strategy = aStrategy;
    }

    void sort()
    {
        strategy->sort();
    }
};

int main()
{
    SorterMerchant sorter;

    MergeSort *mSort = new MergeSort();
    sorter.setStrategy(mSort);
    sorter.sort();

    BubbleSort *bSort = new BubbleSort();
    sorter.setStrategy(bSort);
    sorter.sort();

    delete mSort;
    delete bSort;

    return 0;
}