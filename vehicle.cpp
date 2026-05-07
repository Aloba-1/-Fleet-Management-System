//
//  vehicle.cpp
//  FleetProject
//
//  Created by AKE<3
//
#include "../headers/vehicle.h"

int vehicle::vehicleCount= 0;

vehicle::vehicle(string make,string model,int year,double mileage) {
    this->make= make;
    this->model= model;
    this->year= year;
    this->mileage= mileage;
    vehicleCount++;
}

vehicle::vehicle(const vehicle& other) {
    make = other.make;
    model = other.model;
    year = other.year;
    mileage = other.mileage;
    vehicleCount++;
}

vehicle::vehicle(vehicle&& other) {
    make= other.make;
    model= other.model;
    year= other.year;
    mileage= other.mileage;
    vehicleCount++;
}

vehicle::~vehicle() {
    vehicleCount--;
}

void vehicle::Display() const {
    cout <<"Make:"<< make << endl;
    cout <<"Model:"<< model << endl;
    cout <<"Year:"<< year << endl;
    cout <<"Mileage:"<< mileage << endl;
}

string vehicle::GetMake() const {
    return make;
}

string vehicle::GetModel() const {
    return model;
}

int vehicle::GetYear() const {
    return year;
}

double vehicle::GetMileage() const {
    return mileage;
}

int vehicle::GetvehicleCount() {
    return vehicleCount;
}

void vehicle::PrintMaintenancePolicy() {
    cout <<"\nMaintenance Policy"<< endl;
    cout <<"Cars: cost= 100 + (mileage * 0.05)"<< endl;
    cout <<"Trucks: cost= 200 + (mileage * 0.10)+(loadCapacity * 50)"<< endl;
}


