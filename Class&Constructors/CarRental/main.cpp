#include <iostream>
#include <string>
using namespace std;

class Car
{
protected:
    string m_model;
    int m_year;
    double m_pricePerDay;
    int m_days;
    string m_renter;

public:
    Car(string model, int year, double pricePerDay, int days, string renter)
        : m_model{model}, m_year{year}, m_pricePerDay{pricePerDay}, m_days{days}, m_renter{renter}
    {}

    virtual string getCarType() = 0;
    virtual string getFuelType() = 0;

    virtual void getInfo()
    {
        cout << "Renter Name   : " << m_renter      << "\n";
        cout << "Vehicle Type  : " << getCarType()  << "\n";
        cout << "Fuel Type     : " << getFuelType() << "\n";
        cout << "Model         : " << m_model       << "\n";
        cout << "Year          : " << m_year        << "\n";
        cout << "Price Per Day : $" << m_pricePerDay << "\n";
        cout << "Rent Days     : " << m_days        << "\n";
        cout << "Total Price   : $" << totalPrice() << "\n";
        cout << "----------------------------\n";
    }

    double totalPrice()
    {
        return m_days * m_pricePerDay;
    }

    virtual ~Car() {} // Good practice: virtual destructor for base class
};

class Sedan : public Car
{
private:
    int m_seats;

public:
    Sedan(string model, int year, double pricePerDay, int days, string renter, int seats)
        : Car{model, year, pricePerDay, days, renter}, m_seats{seats}
    {}

    string getCarType() override { return "Sedan"; }
    string getFuelType() override { return "Petrol"; }

    void getInfo() override
    {
        Car::getInfo();
        cout << "Seats         : " << m_seats << "\n";
        cout << "----------------------------\n";
    }
};

class SUV : public Car
{
private:
    int m_seats;

public:
    SUV(string model, int year, double pricePerDay, int days, string renter, int seats)
        : Car{model, year, pricePerDay, days, renter}, m_seats{seats}
    {}

    string getCarType() override { return "SUV"; }        // Fixed: was "Sedan"
    string getFuelType() override { return "Diesel"; }    // Fixed: SUVs commonly Diesel

    void getInfo() override
    {
        Car::getInfo();
        cout << "Seats         : " << m_seats << "\n";
        cout << "----------------------------\n";
    }
};

class ElectricCar : public Car
{
private:
    int m_batteryRange; // in km

public:
    ElectricCar(string model, int year, double pricePerDay, int days, string renter, int batteryRange)
        : Car{model, year, pricePerDay, days, renter}, m_batteryRange{batteryRange}
    {}

    string getCarType() override { return "Electric Car"; }
    string getFuelType() override { return "Electric"; }

    void getInfo() override
    {
        Car::getInfo();
        cout << "Battery Range : " << m_batteryRange << " km\n";
        cout << "----------------------------\n";
    }
};

int main()
{
    // Using base class pointer (polymorphism in action)
    Car* cars[3];

    cars[0] = new Sedan("Toyota Camry", 2022, 45.99, 3, "Alice", 5);
    cars[1] = new SUV("Ford Explorer", 2023, 75.00, 5, "Bob", 7);
    cars[2] = new ElectricCar("Tesla Model 3", 2024, 90.00, 2, "Carol", 560);

    cout << "\n===== Car Rental Receipts =====\n\n";

    for (int i = 0; i < 3; i++)
    {
        cars[i]->getInfo();
    }

    // Clean up memory
    for (int i = 0; i < 3; i++)
    {
        delete cars[i];
    }

    return 0;
}