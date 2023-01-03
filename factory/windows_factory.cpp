#include <iostream>

// utility to avoid ugly looking code
std::string spaces(int v)
{
    std::string tmp;
    tmp.append("\n");
    while (v--)
        tmp.append("\t");
    return tmp;
}

class Product
{
public:
    Product() { std::cout << spaces(3) << "Product ctor"; }

    virtual ~Product(){};

public:
    virtual std::string Product_Operation() = 0;
};

class ProductWindows : public Product
{
public:
    std::string Product_Operation() override
    {
        return "Product WINDOWS Operation";
    }
};

class Creator
{
public:
    Creator() { std::cout << "\nCreator ctor"; }

    virtual ~Creator(){};

public:
    virtual Product *Factory_Method() const = 0;

    void Creator_Operation() const
    {
        std::cout << spaces(2) << "Creator_Operation";

        Product *pEachProduct = this->Factory_Method();

        std::cout << spaces(4) << pEachProduct->Product_Operation();

        delete pEachProduct;
    };
};

class CreatorWindows : public Creator
{
public:
    Product *Factory_Method() const override
    {
        return new ProductWindows();
    }
};

void Client_Codebase(const Creator &obj)
{
    std::cout << spaces(1) << "Client_Codebase";
    obj.Creator_Operation();
}

int main()
{
    Creator *pCreatorWindows = new CreatorWindows();
    Client_Codebase(*pCreatorWindows);

    std::cout << spaces(0);

    return 0;
}