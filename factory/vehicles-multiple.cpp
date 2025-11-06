#include <iostream>
#include <memory>
#include <string>

class Vehicle
{
public:
    virtual void drive() = 0;
    virtual ~Vehicle() = default;
};

class Bike : public Vehicle
{
public:
    void drive() override
    {
        std::cout << "Riding a generic bike.\n";
    }
};

class Aprilia : public Bike
{
public:
    void drive() override
    {
        std::cout << "Riding an Aprilia!\n";
    }
};

class Yamaha : public Bike
{
public:
    void drive() override
    {
        std::cout << "Riding a Yamaha!\n";
    }
};

class VehicleFactory
{
public:
    virtual std::unique_ptr<Vehicle> createVehicle(const std::string &type) = 0;
    virtual ~VehicleFactory() = default;
};

class BikeFactory : public VehicleFactory
{
public:
    std::unique_ptr<Vehicle> createVehicle(const std::string &type) override
    {
        if (type == "Aprilia")
            return std::make_unique<Aprilia>();
        else if (type == "Yamaha")
            return std::make_unique<Yamaha>();
        else
            return std::make_unique<Bike>(); // default
    }
};

int main()
{
    BikeFactory factory;

    auto bike1 = factory.createVehicle("Aprilia");
    auto bike2 = factory.createVehicle("Yamaha");

    bike1->drive();
    bike2->drive();

    return 0;
}
