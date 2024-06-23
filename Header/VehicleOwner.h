#ifndef VEHICLEOWNER_H
#define VEHICLEOWNER_H

#include <string>
#include <vector>
#include <iostream>
#include "Vehicle.h"

using namespace std;

class Vehicle;

class VehicleOwner {
private:
    string name;
    string contactNo;
    string cnic;
    string address;
    double totalMoneyFromRent;
    vector<Vehicle*> ownedVehicles;

public:
    VehicleOwner();
    VehicleOwner(string nm, string contact, string cn, string addr);

    void display() const;
    void input();
    void addVehicle(Vehicle* vehicle);
    string getName() const {
        return name;
    }
    double getTotalMoneyFromRent() const {
        return totalMoneyFromRent;
    }
    void updateTotalMoneyFromRent(double amount);

    void saveToFile(ofstream &out) const;
    void loadFromFile(ifstream &in, vector<Vehicle> &vehicles);

    friend class Vehicle;
    friend class Customer;
};

#endif // VEHICLEOWNER_H
