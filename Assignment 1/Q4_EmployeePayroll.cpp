#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    int empID;
    string empName;
    double empSalary;

public:

    Employee() : empID(0), empName(""), empSalary(0.0) {}

    int getEmpID() const { return empID; }
    void setEmpID(int id) { empID = id; }

    string getEmpName() const { return empName; }
    void setEmpName(const string& name) { empName = name; }

    double getEmpSalary() const { return empSalary; }
    void setEmpSalary(double salary) { empSalary = salary; }

    double calculateGrossSalary() {
        double bonus = 0.0;

        if (empSalary <= 5000) {
            bonus = empSalary * 0.10; 
        } else if (empSalary > 5000 && empSalary <= 10000) {
            bonus = empSalary * 0.15; 
        } else if (empSalary > 10000) {
            bonus = empSalary * 0.20; 
        }

        return empSalary + bonus;
    }

    void displayEmployeeDetails() {
        if (empID == 0) {
            cout << "No employee data available. Please add an employee first." << endl;
            return;
        }

        cout << "\n--- Employee Details ---" << endl;
        cout << "ID: " << empID << endl;
        cout << "Name: " << empName << endl;
        cout << "Basic Salary: Rs. " << empSalary << endl;
        cout << "Gross Salary: Rs. " << calculateGrossSalary() << endl;
        cout << "------------------------" << endl;
    }
};

int main() {
    Employee emp;
    int choice;
    int id;
    string name;
    double salary;

    do {
        cout << "\n--- Employee Payroll Management System ---\n";
        cout << "1. Add a new employee\n";
        cout << "2. Calculate the gross salary\n";
        cout << "3. Display the employee details\n";
        cout << "4. Update employee information\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Employee ID: ";
                cin >> id;
                emp.setEmpID(id);

                cout << "Enter Employee Name: ";
                cin.ignore();
                getline(cin, name);
                emp.setEmpName(name);

                cout << "Enter Basic Salary: ";
                cin >> salary;
                emp.setEmpSalary(salary);

                cout << "Employee added successfully!" << endl;
                break;

            case 2:
                if (emp.getEmpID() == 0) {
                    cout << "Please add an employee first." << endl;
                } else {
                    cout << "Gross Salary for " << emp.getEmpName() << " is Rs. " << emp.calculateGrossSalary() << endl;
                }
                break;

            case 3:
                emp.displayEmployeeDetails();
                break;

            case 4:
                if (emp.getEmpID() == 0) {
                    cout << "Please add an employee first before updating." << endl;
                } else {
                    cout << "Updating details for ID " << emp.getEmpID() << "..." << endl;
                    cout << "Enter new Employee Name: ";
                    cin.ignore();
                    getline(cin, name);
                    emp.setEmpName(name);

                    cout << "Enter new Basic Salary: ";
                    cin >> salary;
                    emp.setEmpSalary(salary);

                    cout << "Employee information updated successfully!" << endl;
                }
                break;

            case 5:
                cout << "Exiting system. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
