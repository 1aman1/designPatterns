#include "notification.h"

int main()
{
    std::unique_ptr<Notification> smsNotif = std::make_unique<SMSNotification>();
    smsNotif->send("Hello, this is single channel test notification!");

    std::unique_ptr<Notification> whatsappNotif = std::make_unique<WhatsappNotification>(std::move(smsNotif));
    whatsappNotif->send("Hello, this is dual channel test notification!");

    return 0;
}