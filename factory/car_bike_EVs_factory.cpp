#include <iostream>

class Product
{
public:
    virtual ~Product(){};
    virtual std::string product_operation() = 0;
};

class specificProduct_1 : public Product
{
public:
    std::string product_operation() override
    {
        return ": made with specificProduct_1\n";
    }
};

class specificProduct_2 : public Product
{
public:
    std::string product_operation() override
    {
        return ": made with specificProduct_2\n";
    }
};

// -----------------------

class creator_t
{
public:
    virtual ~creator_t(){};
    virtual Product *factory_method() const = 0;

    // some useful logic
    // + this clubs creation, where addition of more specific creators wouldn't require any updates

    std::string creator_operation() const
    {
        Product *ptr_spcfc_product = this->factory_method();
        std::string result = " : inside creator context " + ptr_spcfc_product->product_operation();
        delete ptr_spcfc_product;
        return result;
    }
};

class specific_creator_1 : public creator_t
{
public:
    Product *factory_method() const override
    {
        return new specificProduct_1();
    }
};

class specific_creator_2 : public creator_t
{
public:
    Product *factory_method() const override
    {
        return new specificProduct_2();
    }
};

void customer_code(const creator_t &Creator)
{
    std::cout << ": customer code here"
              << Creator.creator_operation();
}

//

/* business decision to keep making cars, bikes adds
that now we make EVs as well */

/* new EV code */
class specificProduct_3 : public Product
{
public:
    std::string product_operation() override
    {
        return ": made with specificProduct_3\n";
    }
};

class specific_creator_3 : public creator_t
{
public:
    Product *factory_method() const override
    {
        return new specificProduct_3();
    }
};

/**/

int main()
{
    std::cout << "\nptr_creator_1";
    creator_t *ptr_creator_1 = new specific_creator_1();
    customer_code(*ptr_creator_1);

    std::cout << "\nptr_creator_2";
    creator_t *ptr_creator_2 = new specific_creator_2();
    customer_code(*ptr_creator_2);

    delete ptr_creator_1;
    delete ptr_creator_2;

    /* new EV code */

    std::cout << "\nptr_creator_3";
    creator_t *ptr_creator_3 = new specific_creator_3();
    customer_code(*ptr_creator_3);

    delete ptr_creator_3;
    
    /**/

    return 0;
}