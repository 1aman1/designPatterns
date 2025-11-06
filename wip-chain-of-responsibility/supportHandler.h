// guards
#ifndef SUPPORTHANDLER_H
#define SUPPORTHANDLER_H

#include <memory>
// #include<iostream>

// Request
enum Priority
{
    FREE,
    PREMIUM,
    ELITE
};

class Request
{
private:
    Priority priority;

public:
    Request(Priority p);
    Priority getPriority() const;
};

class SupportHandler
{
public:
    virtual ~SupportHandler() = default;

    virtual void handleRequest(std::unique_ptr<Request> request) = 0;
    virtual void setNext(std::unique_ptr<SupportHandler> next) = 0;
};

class FreeSupportHandler : public SupportHandler
{
public:
    void handleRequest(std::unique_ptr<Request> request) override;
    void setNext(std::unique_ptr<SupportHandler> next) override;

private:
    std::unique_ptr<SupportHandler> nextHandler;
};

class PremiumSupportHandler : public SupportHandler
{
public:
    void handleRequest(std::unique_ptr<Request> request) override;
    void setNext(std::unique_ptr<SupportHandler> next) override;

private:
    std::unique_ptr<SupportHandler> nextHandler;
};

class EliteSupportHandler : public SupportHandler
{
public:
    void handleRequest(std::unique_ptr<Request> request) override;
    void setNext(std::unique_ptr<SupportHandler> next) override;

private:
    std::unique_ptr<SupportHandler> nextHandler;
};

#endif // SUPPORTHANDLER_H