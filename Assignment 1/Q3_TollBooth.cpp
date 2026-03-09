#include <iostream>

using namespace std;

class TollBooth {
private:
    int totalVehicles;
    double totalRevenue;

    const double TOLL_STANDARD = 180.0;
    const double TOLL_TRUCK = 500.0; 
    const double TOLL_BUS = 350.0;

public:

    TollBooth() : totalVehicles(0), totalRevenue(0.0) {}

    void reset() {
        totalVehicles = 0;
        totalRevenue = 0.0;
        cout << "\nToll booth statistics have been reset.\n";
    }

    void vehiclePayingToll(int vehicleType, double tollAmount) {
        totalVehicles += 1;
        totalRevenue += tollAmount;

        cout << "\nVehicle successfully processed.";
        cout << "\nPaid: Rs. " << tollAmount << endl;
    }

    int getTotalVehicles() const {
        return totalVehicles;
    }

    double getTotalRevenue() const {
        return totalRevenue;
    }

    void addStandardCar() {
        vehiclePayingToll(1, TOLL_STANDARD);
    }

    void addTruck() {
        vehiclePayingToll(2, TOLL_TRUCK);
    }

    void addBus() {
        vehiclePayingToll(3, TOLL_BUS);
    }
};

int main() {
    TollBooth booth;
    int choice;

    do {
        cout << "\n--- Toll Booth Menu ---\n";
        cout << "1. Add a standard car and collect toll\n";
        cout << "2. Add a truck and collect toll\n";
        cout << "3. Add a bus and collect toll\n";
        cout << "4. Display total cars passed\n";
        cout << "5. Display total revenue collected\n";
        cout << "6. Reset booth statistics\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                booth.addStandardCar();
                break;
            case 2:
                booth.addTruck();
                break;
            case 3:
                booth.addBus();
                break;
            case 4:
                cout << "\nTotal vehicles passed: " << booth.getTotalVehicles() << endl;
                break;
            case 5:
                cout << "\nTotal revenue collected: Rs. " << booth.getTotalRevenue() << endl;
                break;
            case 6:
                booth.reset();
                break;
            case 7:
                cout << "\nExiting program...\n";
                break;
            default:
                cout << "\nInvalid choice. Please select a number between 1 and 7.\n";
        }
    } while (choice != 7);

    return 0;
}
