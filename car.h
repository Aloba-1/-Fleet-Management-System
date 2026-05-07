//
//  Car.h
//  FleetProject
//
//  Created by AKE<3 
//
#ifndef CAR_H
#define CAR_H

#include "vehicle.h"

class Car:public vehicle {
private:
    int doors;
    bool automatic;

public:
    Car(string make, string model, int year, double mileage, int doors, bool automatic);
    Car(const Car& other);
    Car(Car&& other);

    void Display() const override;
    double CalculateMaintenanceCost() const override;
    string GetType() const override;
};

#endif


