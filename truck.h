//
//  truck.h
//  FleetProject
//
//  Created by AKE<3 
//
#ifndef TRUCK_H
#define TRUCK_H

#include"vehicle.h"

class truck : public vehicle {
private:
    double loadCapacity;
    int axles;

public:
    truck(string make, string model, int year, double mileage, double loadCapacity, int axles);
    truck(const truck& other);
    truck(truck&& other);

    void Display() const override;
    double CalculateMaintenanceCost() const override;
    string GetType() const override;
};
#endif


