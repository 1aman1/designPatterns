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
class Sorter
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
    Sorter sortingHandle;

    MergeSort *mSort = new MergeSort();
    sortingHandle.setStrategy(mSort);
    sortingHandle.sort();

    BubbleSort *bSort = new BubbleSort();
    sortingHandle.setStrategy(bSort);
    sortingHandle.sort();

    delete mSort;
    delete bSort;

    return 0;
}

/*
The SortingStrategy class is the Strategy interface. It declares the sort() method that represents the behavior to be performed.

The BubbleSort and MergeSort classes are concrete strategies that implement the sort() method according to their specific sorting algorithms.

The Sorter class is the context that maintains a reference to a SortingStrategy object. It has a setStrategy() method to set the strategy and a sortArray() method that delegates the sorting behavior to the strategy. */

/* THE STRATEGY PATTERN ALLOWS YOU TO DECOUPLE THE ALGORITHM OR BEHAVIOR FROM THE CLIENT CODE THAT USES IT. IT PROVIDES FLEXIBILITY IN CHOOSING AND SWITCHING BETWEEN DIFFERENT STRATEGIES AT RUNTIME. THIS IS PARTICULARLY USEFUL WHEN YOU HAVE MULTIPLE ALGORITHMS OR BEHAVIORS THAT NEED TO BE INTERCHANGEABLE WITHOUT MODIFYING THE CLIENT CODE.
 */