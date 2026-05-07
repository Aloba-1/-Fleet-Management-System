//
//  main.cpp
//  FleetProject
//
//  Created by AKE<3
//
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "../headers/vehicle.h"
#include "../headers/car.h"
#include "../headers/truck.h"

using namespace std;
void LoadvehiclesFromFile(vector<vehicle*>& vehicles) {
    ifstream file("resources/vehicles.txt");

    if (!file) {
        cout << "vehicles.txt file not found. You can still create vehicles manually." << endl;
        return;
    }

    string line;

    while (getline(file, line)) {
        // Skip empty lines
        if (line.empty()) {
            continue;
        }

        // Skip comment lines that start with #
        if (line[0] == '#') {
            continue;
        }

        stringstream ss(line);

        string type;
        string make;
        string model;
        string yearStr;
        string mileageStr;
        string extra1Str;
        string extra2Str;

        getline(ss, type, ',');
        getline(ss, make, ',');
        getline(ss, model, ',');
        getline(ss, yearStr, ',');
        getline(ss, mileageStr, ',');
        getline(ss, extra1Str, ',');
        getline(ss, extra2Str, ',');

        int year = stoi(yearStr);
        double mileage = stod(mileageStr);

        if (type == "Car") {
            int doors = stoi(extra1Str);
            bool automatic = stoi(extra2Str);

            vehicles.push_back(new Car(make, model, year, mileage, doors, automatic));
        }
        else if (type == "truck") {
            double loadCapacity = stod(extra1Str);
            int axles = stoi(extra2Str);

            vehicles.push_back(new truck(make, model, year, mileage, loadCapacity, axles));
        }
    }

    file.close();
}

void CreateCar(vector<vehicle*>& vehicles) {
    string make, model;
    int year, doors;
    double mileage;
    bool automatic;

    cout << "\nEnter make: ";
    cin >> make;

    cout << "Enter model: ";
    cin >> model;

    cout << "Enter year: ";
    cin >> year;

    cout << "Enter mileage: ";
    cin >> mileage;

    cout << "Enter number of doors: ";
    cin >> doors;

    cout << "Automatic? Enter 1 for yes, 0 for no: ";
    cin >> automatic;

    vehicles.push_back(new Car(make, model, year, mileage, doors, automatic));

    cout << "Car created successfully." << endl;
}

void CreateTruck(vector<vehicle*>& vehicles) {
    string make, model;
    int year, axles;
    double mileage, loadCapacity;

    cout << "\nEnter make: ";
    cin >> make;

    cout << "Enter model: ";
    cin >> model;

    cout << "Enter year: ";
    cin >> year;

    cout << "Enter mileage: ";
    cin >> mileage;

    cout << "Enter load capacity: ";
    cin >> loadCapacity;

    cout << "Enter number of axles: ";
    cin >> axles;

    vehicles.push_back(new truck(make, model, year, mileage, loadCapacity, axles));

    cout << "Truck created successfully." << endl;
}

void DisplayAllVehicles(const vector<vehicle*>& vehicles) {
    if (vehicles.empty()) {
        cout << "\nNo vehicles to display." << endl;
        return;
    }

    cout << "\nAll vehicles" << endl;

    for (int i = 0; i < vehicles.size(); i++) {
        cout << "\nvehicle #" << i + 1 << endl;
        vehicles[i]->Display();
    }
}

void ShowMaintenanceCosts(const vector<vehicle*>& vehicles) {
    if (vehicles.empty()) {
        cout << "\nNo vehicles available." << endl;
        return;
    }

    cout << "\nMaintenance Costs" << endl;

    for (int i = 0; i < vehicles.size(); i++) {
        cout << "\nvehicle #" << i + 1 << endl;
        cout << "Type: " << vehicles[i]->GetType() << endl;
        cout << "Maintenance Cost: $" << vehicles[i]->CalculateMaintenanceCost() << endl;
    }
}

int main() {
    vector<vehicle*> vehicles;
    int choice;

    LoadvehiclesFromFile(vehicles);

    do {
        cout << "\n=================" << endl;
        cout << "Fleet Project Menu" << endl;
        cout << "===================" << endl;
        cout << "1. Create Car" << endl;
        cout << "2. Create Truck" << endl;
        cout << "3. Display all vehicles" << endl;
        cout << "4. Show maintenance cost for each" << endl;
        cout << "5. Show total number of vehicles" << endl;
        cout << "6. Print maintenance policy" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                CreateCar(vehicles);
                break;

            case 2:
                CreateTruck(vehicles);
                break;

            case 3:
                DisplayAllVehicles(vehicles);
                break;

            case 4:
                ShowMaintenanceCosts(vehicles);
                break;

            case 5:
                cout << "\nTotal number of vehicles: " << vehicle::GetvehicleCount() << endl;
                break;

            case 6:
                vehicle::PrintMaintenancePolicy();
                break;

            case 7:
                cout << "\nExiting program..." << endl;
                break;

            default:
                cout << "\nInvalid choice. Try again." << endl;
        }

    } while (choice != 7);

    for (int i = 0; i < vehicles.size(); i++) {
        delete vehicles[i];
    }

    return 0;
}
