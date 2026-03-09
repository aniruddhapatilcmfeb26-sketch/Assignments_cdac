#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    const int employeeId;
    string name;
    float salary;

public:

    Employee(int id, string empName, float empSalary) 
        : employeeId(id), name(empName), salary(empSalary) {

    }

    void displayDetails() const {
        cout << "Employee ID: " << employeeId << " (const)" << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: Rs. " << salary << endl;
    }
};

int main() {
    Employee emp(9091, "Charlie", 75000.0f);

    cout << "--- Employee Details ---" << endl;
    emp.displayDetails();

    return 0;
}
