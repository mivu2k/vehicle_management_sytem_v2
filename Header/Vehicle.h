#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <fstream>

using namespace std;

class Vehicle {
private:
    int id;
    string make;
    string model;
    int year;
    double mileage;
    double rentalRates;
    string fuelType;
    string plateNumber;
    string category;
    string location;
    bool isRented;

public:
    Vehicle();
    Vehicle(int id, string mk, string mdl, int yr, double mile, double rate, string fuel, string plate, string cat, string loc);

    void display() const;
    void input();

    void saveToFile(ofstream &out) const;
    void loadFromFile(ifstream &in);

    int getId() const {
        return id;
    }
    string getMake() const {
        return make;
    }
    string getModel() const {
        return model;
    }
    double getRentalRates() const {
        return rentalRates;
    }
    bool getIsRented() const {
        return isRented;
    }
    void setIsRented(bool rented) {
        isRented = rented;
    }

    friend class VehicleOwner;
    friend class Customer;
};

#endif // VEHICLE_H
