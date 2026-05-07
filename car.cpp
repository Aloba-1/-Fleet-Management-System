//
//  Car.cpp
//  FleetProject
//
//  Created by AKE<3
//
#include "../headers/car.h"

Car::Car(string make, string model, int year, double mileage, int doors, bool automatic)
    : vehicle(make, model, year, mileage) {
    this->doors = doors;
    this->automatic = automatic;
}

Car::Car(const Car& other)
    : vehicle(other) {
    doors = other.doors;
    automatic = other.automatic;
}

Car::Car(Car&& other)
    : vehicle(other) {
    doors = other.doors;
    automatic = other.automatic;
}

void Car::Display() const {
    cout << "\nvehicle Type: Car" << endl;
    vehicle::Display();
    cout << "Doors: " << doors << endl;

    if (automatic) {
        cout << "Transmission: Automatic" << endl;
    } else {
        cout << "Transmission: Manual" << endl;
    }
}

double Car::CalculateMaintenanceCost() const {
    return 100 + (GetMileage() * 0.05);
}

string Car::GetType() const {
    return "Car";
}


