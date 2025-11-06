#include <iostream>

class Vehicle
{
public:
    virtual void drive() = 0;
    virtual ~Vehicle() = default;
};

class VehicleFactory
{
public:
    virtual Vehicle *manufactureVehicle() = 0;
    virtual ~VehicleFactory() = default;
};

class Aprilia : public Vehicle
{
public:
    void drive() override
    {
        std::cout << "It's Aprilia \n";
    }
};

class BMW : public Vehicle
{
public:
    void drive() override
    {
        std::cout << "It's BMW \n";
    }
};

class ApriliaFactory : public VehicleFactory
{
public:
    Vehicle *manufactureVehicle() override
    {
        return new Aprilia();
    }
};

class BMWFactory : public VehicleFactory
{
public:
    Vehicle *manufactureVehicle() override
    {
        return new BMW();
    }
};

int main()
{
    VehicleFactory *apriliaFactory = new ApriliaFactory();
    Vehicle *firstBike = apriliaFactory->manufactureVehicle();
    firstBike->drive();

    VehicleFactory *bmwFactory = new BMWFactory();
    Vehicle *secondBike = bmwFactory->manufactureVehicle();
    secondBike->drive();

    return 0;
}