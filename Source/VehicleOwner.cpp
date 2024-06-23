#include "../Header/VehicleOwner.h"
#include <iomanip>

VehicleOwner::VehicleOwner() : name(""), contactNo(""), cnic(""), address(""), totalMoneyFromRent(0) {}

VehicleOwner::VehicleOwner(string nm, string contact, string cn, string addr)
        : name(nm), contactNo(contact), cnic(cn), address(addr), totalMoneyFromRent(0) {}

void VehicleOwner::display() const {
    cout << setw(15) << name
         << setw(15) << contactNo
         << setw(25) << cnic
         << setw(35) << address
         << setw(25) << totalMoneyFromRent
         << endl;

    if (!ownedVehicles.empty()) {
        cout << "Owned Vehicles:" << endl;
        for (auto vehicle : ownedVehicles) {
            vehicle->display();
        }
    }
}

void VehicleOwner::input() {
    cout << "Enter Owner Name: ";
    cin >> name;
    cout << "Enter Contact No: ";
    cin >> contactNo;
    cout << "Enter CNIC: ";
    cin >> cnic;
    cout << "Enter Address: ";
    cin >> address;
}

void VehicleOwner::addVehicle(Vehicle* vehicle) {
    ownedVehicles.push_back(vehicle);
}

void VehicleOwner::updateTotalMoneyFromRent(double amount) {
    totalMoneyFromRent += amount;
}

void VehicleOwner::saveToFile(ofstream &out) const {
    out << name << " " << contactNo << " " << cnic << " " << address << " " << totalMoneyFromRent << " ";
    out << ownedVehicles.size() << " ";
    for (auto vehicle : ownedVehicles) {
        out << vehicle->getId() << " ";
    }
    out << "\n";
}

void VehicleOwner::loadFromFile(ifstream &in, vector<Vehicle> &vehicles) {
    in >> name >> contactNo >> cnic >> address >> totalMoneyFromRent;
    int ownedVehicleCount;
    in >> ownedVehicleCount;
    ownedVehicles.clear();
    for (int i = 0; i < ownedVehicleCount; ++i) {
        int ownedVehicleId;
        in >> ownedVehicleId;
        for (auto &vehicle : vehicles) {
            if (vehicle.getId() == ownedVehicleId) {
                ownedVehicles.push_back(&vehicle);
                break;
            }
        }
    }
}
