#include "Prices.h"
#include <iostream>

void RegularPricing::calculatePrice(const std::string &product)
{
    std::cout << "Calculating regular price for " << product << std::endl;
}

void FestivePricing::calculatePrice(const std::string &product)
{
    std::cout << "Calculating festive price for " << product << std::endl;
}

void PaymentDesk::setStrategy(std::unique_ptr<PricingStrategy> aStrategy)
{
    this->priceStrategy = std::move(aStrategy);
}

void PaymentDesk::getPrice(const std::string &product)
{
    if (priceStrategy)
        priceStrategy->calculatePrice(product);
    else
    {
        std::cout << "Pricing strategy not set!" << std::endl;
    }
}
