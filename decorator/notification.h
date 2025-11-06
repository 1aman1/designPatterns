#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <string>

class Notification
{
public:
    virtual void send(const std::string &msg) = 0;
    virtual ~Notification() = default;
};

class SMSNotification : public Notification
{
public:
    void send(const std::string &msg) override;
};

class NotificationDecorator : public Notification
{
public:
    explicit NotificationDecorator(std::unique_ptr<Notification> notif);
    void send(const std::string &msg) override;

private:
    std::unique_ptr<Notification> wrappedNotification;
};

class WhatsappNotification : public NotificationDecorator
{
public:
    WhatsappNotification(std::unique_ptr<Notification> notif);
    void send(const std::string &msg) override;
};

#endif // NOTIFICATION_H