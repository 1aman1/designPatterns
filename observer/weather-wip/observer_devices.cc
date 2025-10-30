#include "observer_devices.h"

// definition
void MobileDevice::update(std::string message)
{
    std::cout << "mobiledevice got update";
}

void LaptopDevice::update(std::string message)
{
    std::cout << "LaptopDevice got update";
}