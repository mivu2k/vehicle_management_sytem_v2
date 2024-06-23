#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include <iostream>
#include "Vehicle.h"
#include "VehicleOwner.h"

using namespace std;

class Vehicle;

class Customer {
private:
    string name;
    string contactNo;
    string cnic;
    string address;
    double totalPayable;
    vector<Vehicle*> rentedVehicles;

public:
    Customer();
    Customer(string nm, string contact, string cn, string addr);

    void display() const;
    void input();
    void rentVehicle(Vehicle* vehicle, VehicleOwner* owner, bool withFuel, const string& rentType, double distance, int days);

    string getName() const {
        return name;
    }
    double getTotalPayable() const {
        return totalPayable;
    }

    void saveToFile(ofstream &out) const;
    void loadFromFile(ifstream &in, vector<Vehicle> &vehicles);

    friend class Vehicle;
    friend class VehicleOwner;
};

#endif // CUSTOMER_H
