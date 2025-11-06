#include "supportHandler.h"

Request::Request(Priority p)
    : priority(p) {}

Priority Request::getPriority() const { return priority; }

void FreeSupportHandler::setNext(std::unique_ptr<SupportHandler> next)
{
    nextHandler = std::move(next);
}

void FreeSupportHandler::handleRequest(std::unique_ptr<Request> request)
{
    if (request->getPriority() == FREE)
    {
        std::cout << "Free support handled the request.\n";
    }
    else if (nextHandler)
    {
        nextHandler->handleRequest(std::move(request));
    }
    else
    {
        std::cout << "Request doesn't exist OR invalid request type\n";
    }
}

void PaidSupportHandler::setNext(std::unique_ptr<SupportHandler> next)
{
    nextHandler = std::move(next);
}

void PaidSupportHandler::handleRequest(std::unique_ptr<Request> request)
{
    if (request->getPriority() == PAID)
    {
        std::cout << "Paid support handled the request.\n";
    }
    else if (nextHandler)
    {
        nextHandler->handleRequest(std::move(request));
    }
    else
    {
        std::cout << "Request doesn't exist OR invalid request type\n";
    }
}

void PremiumSupportHandler::setNext(std::unique_ptr<SupportHandler> next)
{
    nextHandler = std::move(next);
}

void PremiumSupportHandler::handleRequest(std::unique_ptr<Request> request)
{
    if (request->getPriority() == PREMIUM)
    {
        std::cout << "Premium support handled the request.\n";
    }
    else if (nextHandler)
    {
        nextHandler->handleRequest(std::move(request));
    }
    else
    {
        std::cout << "Request doesn't exist OR invalid request type\n";
    }
}