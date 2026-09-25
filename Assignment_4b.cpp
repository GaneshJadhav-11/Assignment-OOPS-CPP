#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
    int vehicleId;
    string vehicleName;
    float rent;

public:

    void getdata()
    {
        cout << "Enter Vehicle ID: ";
        cin >> vehicleId;

        cout << "\nEnter Vehicle Name: ";
        cin >> vehicleName;
    }

    virtual void calculate_rent()
    {
        cout << "Rental Amount: ";
    }

    void displaydata()
    {
        cout << "\nVehicle ID: " << vehicleId;
        cout << "\nVehicle Name: " << vehicleName;
    }
};


class Car : public Vehicle
{
public:
    int days;

    void calculate_rent()
    {
        cout << "\nEnter number of days: ";
        cin >> days;

        rent = days * 1500;

        displaydata();
        cout << "\nNumber of Days: " << days;
        cout << "\nTotal Rent: " << rent;
    }
};


class Bike : public Vehicle
{
public:
    int days;

    void calculate_rent()
    {
        cout << "\nEnter number of days: ";
        cin >> days;

        rent = days * 500;

        displaydata();
        cout << "\nNumber of Days: " << days;
        cout << "\nTotal Rent: " << rent;
    }
};


int main()
{
    Vehicle *vehicle;

    Car c;
    Bike b;

    int choice;

    cout << "1. Car";
    cout << "\n2. Bike";

    cout << "\nEnter choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            vehicle = &c;
            break;

        case 2:
            vehicle = &b;
            break;

        default:
            cout << "Invalid choice";
            return 0;
    }

    vehicle->getdata();

    vehicle->displaydata();

    vehicle->calculate_rent();

    return 0;
}