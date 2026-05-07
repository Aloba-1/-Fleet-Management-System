
#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <string>
using namespace std;

class vehicle {
private:
    string make;
    string model;
    int year;
    double mileage;
    static int vehicleCount;
    
public:
    vehicle(string make, string model, int year, double mileage);
    vehicle(const vehicle& other);
    vehicle(vehicle&& other);

    virtual ~vehicle();

    virtual void Display() const;
    virtual double CalculateMaintenanceCost() const = 0;
    virtual string GetType() const = 0;

    string GetMake() const;
    string GetModel() const;
    int GetYear() const;
    double GetMileage() const;

    static int GetvehicleCount();
    static void PrintMaintenancePolicy();
};
#endif
