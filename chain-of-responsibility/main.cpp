#include "supportHandler.h"

int main()
{
    std::unique_ptr<SupportHandler> freeHandler = std::make_unique<FreeSupportHandler>();
    std::unique_ptr<SupportHandler> premiumHandler = std::make_unique<PremiumSupportHandler>();
    std::unique_ptr<SupportHandler> eliteHandler = std::make_unique<EliteSupportHandler>();

    // establish the chain of responsibility
    premiumHandler->setNext(std::move(eliteHandler));
    freeHandler->setNext(std::move(premiumHandler));

    // incoming requests
    std::unique_ptr<Request> req1 = std::make_unique<Request>(ELITE);
    freeHandler->handleRequest(std::move(req1));

    std::unique_ptr<Request> req2 = std::make_unique<Request>(PREMIUM);
    freeHandler->handleRequest(std::move(req2));

    std::unique_ptr<Request> req3 = std::make_unique<Request>(FREE);
    freeHandler->handleRequest(std::move(req3));

    return 0;
}