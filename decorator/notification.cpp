#include "notification.h"

#include <iostream>

void SMSNotification::send(const std::string &msg)
{
    std::cout << "Sending SMS: " << msg << std::endl;
}

NotificationDecorator::NotificationDecorator(std::unique_ptr<Notification> wrappee)
    : wrappedNotification(std::move(wrappee))
{
}

void NotificationDecorator::send(const std::string &msg)
{
    if (wrappedNotification)
    {
        wrappedNotification->send(msg);
    }
}

WhatsappNotification::WhatsappNotification(std::unique_ptr<Notification> wrappee)
    : NotificationDecorator(std::move(wrappee))
{
}

void WhatsappNotification::send(const std::string &msg)
{
    NotificationDecorator::send(msg);
    std::cout << "Sending WhatsApp message: " << msg << std::endl;
}