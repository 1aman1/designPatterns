#include "notification.h"

int main()
{
    std::unique_ptr<Notification> smsNotif = std::make_unique<SMSNotification>();
    smsNotif->send("single channel test notification");

    std::unique_ptr<Notification> sms_whatsappNotif = std::make_unique<WhatsappNotification>(std::move(smsNotif));
    sms_whatsappNotif->send("multi-channel test notification");

    return 0;
}