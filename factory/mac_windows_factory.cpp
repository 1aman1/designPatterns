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

/**
 * @brief For a new product below code is added with no need to change client code or product creation code above
 *
 * @return new product ie, Macintosh here
 */

class ProductMacintosh : public Product
{
public:
    std::string Product_Operation() override
    {
        return "Product MACINTOSH Operation";
    }
};

class CreatorMacintosh : public Creator
{
public:
    Product *Factory_Method() const override
    {
        return new ProductMacintosh();
    }
};

//

int main()
{
    Creator *pCreatorWindows = new CreatorWindows();
    Client_Codebase(*pCreatorWindows);

    // new code for Macintosh
    Creator *pCreatorMacintosh = new CreatorMacintosh();
    Client_Codebase(*pCreatorMacintosh);
    //

    std::cout << spaces(0);

    return 0;
}