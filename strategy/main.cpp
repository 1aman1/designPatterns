#include "Prices.h"
#include <iostream>

int main()
{
    std::unique_ptr<PaymentDesk> desk = std::make_unique<PaymentDesk>();

    desk->getPrice("TV"); // No strategy set

    std::unique_ptr<PricingStrategy> regularPricing = std::make_unique<RegularPricing>();
    desk->setStrategy(std::move(regularPricing));
    desk->getPrice("Laptop");

    std::unique_ptr<PricingStrategy> festivePricing = std::make_unique<FestivePricing>();
    desk->setStrategy(std::move(festivePricing));
    desk->getPrice("Smartphone");

    return 0;
}