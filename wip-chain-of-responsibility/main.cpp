#include "supportHandler.h"

int main()
{
    std::unique_ptr<SupportHandler> freeHandler = std::make_unique<FreeSupportHandler>();
    std::unique_ptr<SupportHandler> premiumHandler = std::make_unique<PremiumSupportHandler>();
    std::unique_ptr<SupportHandler> eliteHandler = std::make_unique<EliteSupportHandler>();

    premiumHandler->setNext(std::move(eliteHandler));
    freeHandler->setNext(std::move(premiumHandler));

    std::unique_ptr<Request> req1 = std::make_unique<Request>(FREE);
    freeHandler->handleRequest(std::move(req1));

    return 0;
}