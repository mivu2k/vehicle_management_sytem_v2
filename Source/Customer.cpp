#include "../Header/Customer.h"
#include <iomanip>

Customer::Customer() : name(""), contactNo(""), cnic(""), address(""), totalPayable(0) {}

Customer::Customer(string nm, string contact, string cn, string addr)
        : name(nm), contactNo(contact), cnic(cn), address(addr), totalPayable(0) {}

void Customer::display() const {
    cout << setw(15) << name
         << setw(15) << contactNo
         << setw(25) << cnic
         << setw(35) << address
         << setw(25) << totalPayable
         << endl;

    if (!rentedVehicles.empty()) {
        cout << "Rented Vehicles:" << endl;
        for (auto vehicle : rentedVehicles) {
            vehicle->display();
        }
    }
}

void Customer::input() {
    cout << "Enter Customer Name: ";
    cin >> name;
    cout << "Enter Contact No: ";
    cin >> contactNo;
    cout << "Enter CNIC: ";
    cin >> cnic;
    cout << "Enter Address: ";
    cin >> address;
}

void Customer::rentVehicle(Vehicle* vehicle, VehicleOwner* owner, bool withFuel, const string& rentType, double distance, int days) {
    double rent = vehicle->getRentalRates();
    if (withFuel) {
        if (distance > 50) {
            rent += 50;
            rent += (distance - 50) * 0.5;
        }
    } else {
        if (distance > 50) {
            rent += 10;
            rent += (distance - 50) * 0.5;
        }
    }

    if (days >= 7 && days < 14) {
        rent *= 1.1;
    } else if (days >= 14 && days < 30) {
        rent *= 1.15;
    } else if (days >= 30) {
        rent *= 1.25;
    }

    totalPayable += rent;
    owner->updateTotalMoneyFromRent(rent);
    rentedVehicles.push_back(vehicle);
}

void Customer::saveToFile(ofstream &out) const {
    out << name << " " << contactNo << " " << cnic << " " << address << " " << totalPayable << " ";
    out << rentedVehicles.size() << " ";
    for (auto vehicle : rentedVehicles) {
        out << vehicle->getId() << " ";
    }
    out << "\n";
}

void Customer::loadFromFile(ifstream &in, vector<Vehicle> &vehicles) {
    in >> name >> contactNo >> cnic >> address >> totalPayable;
    int rentedVehicleCount;
    in >> rentedVehicleCount;
    rentedVehicles.clear();
    for (int i = 0; i < rentedVehicleCount; ++i) {
        int rentedVehicleId;
        in >> rentedVehicleId;
        for (auto &vehicle : vehicles) {
            if (vehicle.getId() == rentedVehicleId) {
                rentedVehicles.push_back(&vehicle);
                break;
            }
        }
    }
}
