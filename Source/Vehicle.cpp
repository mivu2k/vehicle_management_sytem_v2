#include "../Header/Vehicle.h"
#include <iostream>
#include <iomanip>

Vehicle::Vehicle() : id(0), make(""), model(""), year(0), mileage(0), rentalRates(0), fuelType(""), plateNumber(""), category(""), location(""), isRented(false) {}

Vehicle::Vehicle(int id, string mk, string mdl, int yr, double mile, double rate, string fuel, string plate, string cat, string loc)
        : id(id), make(mk), model(mdl), year(yr), mileage(mile), rentalRates(rate), fuelType(fuel), plateNumber(plate), category(cat), location(loc), isRented(false) {}

void Vehicle::display() const {
    cout << setw(5) << id
         << setw(15) << make
         << setw(15) << model
         << setw(10) << year
         << setw(15) << mileage
         << setw(15) << rentalRates
         << setw(15) << fuelType
         << setw(15) << plateNumber
         << setw(15) << category
         << setw(15) << location
         << setw(10) << (isRented ? "Rented" : "Available")
         << endl;
}

void Vehicle::input() {
    cout << "Enter Vehicle ID: ";
    cin >> id;
    cout << "Enter Make: ";
    cin >> make;
    cout << "Enter Model: ";
    cin >> model;
    cout << "Enter Year: ";
    cin >> year;
    cout << "Enter Mileage: ";
    cin >> mileage;
    cout << "Enter Rental Rates: ";
    cin >> rentalRates;
    cout << "Enter Fuel Type (gasoline, diesel, electric, hybrid): ";
    cin >> fuelType;
    cout << "Enter Plate Number: ";
    cin >> plateNumber;
    cout << "Enter Category (Business and Family Van, Executive, Large Family Car, Large MPV, Large Off-Road, Pick-up, Roadster, Sport, Small Family car, Small MPV, Small Off-Road, Supermini): ";
    cin >> category;
    cout << "Enter Location: ";
    cin >> location;
    isRented = false;
}

void Vehicle::saveToFile(ofstream &out) const {
    out << id << " " << make << " " << model << " " << year << " " << mileage << " " << rentalRates << " "
        << fuelType << " " << plateNumber << " " << category << " " << location << " " << isRented << "\n";
}

void Vehicle::loadFromFile(ifstream &in) {
    in >> id >> make >> model >> year >> mileage >> rentalRates >> fuelType >> plateNumber >> category >> location >> isRented;
}
