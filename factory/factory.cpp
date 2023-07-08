#include <iostream>

/* interfaces */

// Abstract IProduct
class IProduct
{
public:
    virtual void use() = 0;
};

// Abstract Factory
class Factory
{
public:
    virtual IProduct *createProduct() = 0;
};

/* interface implementations */

// Concrete Product Types
class ConcreteProductA : public IProduct
{
public:
    void use() override
    {
        std::cout << "Using ConcreteProductA" << std::endl;
    }
};

class ConcreteProductB : public IProduct
{
public:
    void use() override
    {
        std::cout << "Using ConcreteProductB" << std::endl;
    }
};

// Concrete Factories
class ConcreteFactoryA : public Factory
{
public:
    IProduct *createProduct() override
    {
        return new ConcreteProductA();
    }
};

class ConcreteFactoryB : public Factory
{
public:
    IProduct *createProduct() override
    {
        return new ConcreteProductB();
    }
};

int main()
{
    // Create a factory object
    Factory *factory = new ConcreteFactoryA();

    // Use the factory to create a product
    IProduct *product = factory->createProduct();

    // Use the product
    product->use();

    // Clean up memory
    delete factory;
    delete product;

    // New factory
    // Factory *factoryNew = new ConcreteFactoryB();
    // IProduct *productNew = factoryNew->createProduct();
    // productNew->use();

    // delete factoryNew;
    // delete productNew;

    return 0;
}

/* The IProduct class defines the abstract product interface, which includes the qcCheck() method.

The IProduct interface is implemented by the ConcreteProductA class, which represents a specific concrete product.

The IFactory class defines the abstract factory interface, which includes the makeProduct() method responsible for creating the product.

The ConcreteFactoryA class implements the IFactory interface and provides the implementation for creating a specific product (ConcreteProductA) using the makeProduct() method.

In the main() function, a factory object (ConcreteFactoryA) is created, and the factory's makeProduct() method is used to create a product (ConcreteProductA).

The created product is then used by calling its qcCheck() method.

IT ENCAPSULATES THE PRODUCT CREATION LOGIC WITHIN THE FACTORY CLASS, ALLOWING THE CLIENT CODE TO CREATE PRODUCTS WITHOUT KNOWING THE SPECIFIC CONCRETE CLASS.
*/

/*
N new products can be made by following below implementation example

'''
class ConcreteProductN : public IProduct
{
public:
    void use() override
    {
        std::cout << "Using ConcreteProductN" << std::endl;
    }
};

class ConcreteFactoryN : public Factory
{
public:
    IProduct *createProduct() override
    {
        return new ConcreteProductN();
    }
};

Factory *factory = new ConcreteFactoryN();
'''

*/