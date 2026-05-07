//
//  truck.cpp
//  FleetProject
//
//  Created by AKE<3
//
#include "../headers/truck.h"

truck::truck(string make, string model, int year, double mileage, double loadCapacity, int axles)
    : vehicle(make, model, year, mileage) {
    this->loadCapacity = loadCapacity;
    this->axles = axles;
}

truck::truck(const truck& other)
    : vehicle(other) {
    loadCapacity = other.loadCapacity;
    axles = other.axles;
}

truck::truck(truck&& other)
    : vehicle(other) {
    loadCapacity = other.loadCapacity;
    axles = other.axles;
}

void truck::Display() const {
    cout << "\nvehicle Type: Truck" << endl;
    vehicle::Display();
    cout << "Load Capacity: " << loadCapacity << endl;
    cout << "Axles: " << axles << endl;
}

double truck::CalculateMaintenanceCost() const {
    return 200 + (GetMileage() * 0.10) + (loadCapacity * 50);
}

string truck::GetType() const {
    return "truck";
}


