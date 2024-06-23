#include <iostream>
#include <fstream>
#include <vector>
#include "Header/Vehicle.h"
#include "Header/VehicleOwner.h"
#include "Header/Customer.h"

using namespace std;

void displayOwners(const vector<VehicleOwner>& owners) {
    cout << setw(15) << "Name"
         << setw(15) << "Contact No"
         << setw(25) << "CNIC"
         << setw(35) << "Address"
         << setw(25) << "Total Money"
         << endl;
    for (const auto& owner : owners) {
        owner.display();
    }
}

void displayVehicles(const vector<Vehicle>& vehicles) {
    cout << setw(5) << "ID"
         << setw(15) << "Make"
         << setw(15) << "Model"
         << setw(10) << "Year"
         << setw(15) << "Mileage"
         << setw(15) << "Rates"
         << setw(15) << "Fuel Type"
         << setw(15) << "Plate No"
         << setw(55) << "Category"
         << setw(15) << "Location"
         << setw(10) << "Status"
         << endl;
    for (const auto& vehicle : vehicles) {
        vehicle.display();
    }
}

void displayCustomers(const vector<Customer>& customers) {
    cout << setw(15) << "Name"
         << setw(15) << "Contact No"
         << setw(25) << "CNIC"
         << setw(35) << "Address"
         << setw(25) << "Total Payable"
         << endl;
    for (const auto& customer : customers) {
        customer.display();
    }
}

void saveVehicles(const vector<Vehicle>& vehicles) {
    ofstream outFile("vehicles.txt");
    for (const auto& vehicle : vehicles) {
        vehicle.saveToFile(outFile);
    }
}

void loadVehicles(vector<Vehicle>& vehicles) {
    ifstream inFile("vehicles.txt");
    Vehicle vehicle;
    while (inFile) {
        vehicle.loadFromFile(inFile);
        if (inFile) vehicles.push_back(vehicle);
    }
}

void saveVehicleOwners(const vector<VehicleOwner>& owners) {
    ofstream outFile("vehicleOwners.txt");
    for (const auto& owner : owners) {
        owner.saveToFile(outFile);
    }
}

void loadVehicleOwners(vector<VehicleOwner>& owners, vector<Vehicle>& vehicles) {
    ifstream inFile("vehicleOwners.txt");
    VehicleOwner owner;
    while (inFile) {
        owner.loadFromFile(inFile, vehicles);
        if (inFile) owners.push_back(owner);
    }
}

void saveCustomers(const vector<Customer>& customers) {
    ofstream outFile("customers.txt");
    for (const auto& customer : customers) {
        customer.saveToFile(outFile);
    }
}

void loadCustomers(vector<Customer>& customers, vector<Vehicle>& vehicles) {
    ifstream inFile("customers.txt");
    Customer customer;
    while (inFile) {
        customer.loadFromFile(inFile, vehicles);
        if (inFile) customers.push_back(customer);
    }
}

int main() {
    vector<Vehicle> vehicles;
    vector<VehicleOwner> vehicleOwners;
    vector<Customer> customers;

    loadVehicles(vehicles);
    loadVehicleOwners(vehicleOwners, vehicles);
    loadCustomers(customers, vehicles);

    while (true) {
        cout << "\n1. Add Vehicle Owner\n";
        cout << "2. Add Vehicle\n";
        cout << "3. Add Customer\n";
        cout << "4. Rent Vehicle\n";
        cout << "5. Display Vehicle Owners\n";
        cout << "6. Display Vehicles\n";
        cout << "7. Display Customers\n";
        cout << "8. Save and Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                VehicleOwner owner;
                owner.input();
                vehicleOwners.push_back(owner);
                break;
            }
            case 2: {

                Vehicle vehicle;
                vehicle.input();
                vehicles.push_back(vehicle);
                break;
            }
            case 3: {
                Customer customer;
                customer.input();
                customers.push_back(customer);
                break;
            }
            case 4: {
                if (customers.empty() || vehicles.empty() || vehicleOwners.empty()) {
                    cout << "No customers, vehicles, or vehicle owners available.\n";
                    break;
                }

                cout << "Select Customer:\n";
                for (size_t i = 0; i < customers.size(); ++i) {
                    cout << i + 1 << ". " << customers[i].getName() << "\n";
                }
                int customerIndex;
                cin >> customerIndex;

                cout << "Select Vehicle:\n";
                for (size_t i = 0; i < vehicles.size(); ++i) {
                    if (!vehicles[i].getIsRented()) {
                        cout << i + 1 << ". " << vehicles[i].getMake() << " " << vehicles[i].getModel() << "\n";
                    }
                }
                int vehicleIndex;
                cin >> vehicleIndex;

                cout << "Select Vehicle Owner:\n";
                for (size_t i = 0; i < vehicleOwners.size(); ++i) {
                    cout << i + 1 << ". " << vehicleOwners[i].getName() << "\n";
                }
                int ownerIndex;
                cin >> ownerIndex;

                bool withFuel;
                string rentType;
                double distance;
                int days;

                cout << "With fuel? (1 for yes, 0 for no): ";
                cin >> withFuel;
                cout << "Rent type (within city, out of city): ";
                cin >> rentType;
                cout << "Enter distance (km): ";
                cin >> distance;
                cout << "Enter number of days: ";
                cin >> days;

                customers[customerIndex - 1].rentVehicle(&vehicles[vehicleIndex - 1], &vehicleOwners[ownerIndex - 1], withFuel, rentType, distance, days);
                vehicleOwners[ownerIndex - 1].addVehicle(&vehicles[vehicleIndex - 1]);
                vehicles[vehicleIndex - 1].setIsRented(true);
                break;
            }
            case 5: {
                displayOwners(vehicleOwners);
                break;
            }
            case 6: {
                displayVehicles(vehicles);
                break;
            }
            case 7: {
                displayCustomers(customers);
                break;
            }
            case 8: {
                saveVehicles(vehicles);
                saveVehicleOwners(vehicleOwners);
                saveCustomers(customers);
                cout << "Data saved successfully. Exiting...\n";
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    }
}
