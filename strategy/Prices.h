#ifndef PRICES_H
#define PRICES_H

#include <string>
#include <memory>

class PricingStrategy
{
public:
    virtual void calculatePrice(const std::string &product) = 0;
};

class RegularPricing : public PricingStrategy
{
public:
    void calculatePrice(const std::string &product) override;
};

class FestivePricing : public PricingStrategy
{
public:
    void calculatePrice(const std::string &product) override;
};

class PaymentDesk
{
private:
    std::unique_ptr<PricingStrategy> priceStrategy;

public:
    void setStrategy(std::unique_ptr<PricingStrategy> aStrategy);

    void getPrice(const std::string &product);
};

#endif // PRICES_H