#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    int id;
    string name;
    mutable int accessCount;

public:

    Employee(int empId, string empName) : id(empId), name(empName), accessCount(0) {}

    Employee(const Employee& other) {
        id = other.id;
        name = other.name; 
        accessCount = 0; 
        cout << "User-defined copy constructor called!" << endl;
    }

    void display() const {

        accessCount++;
        cout << "Displaying ID: " << id << " Name: " << name << " | Access Count: " << accessCount << endl;
    }

    int getAccessCount() const { return accessCount; }
};

int main() {

    Employee e1(1, "Alice");
    cout << "--- e1 display calls ---" << endl;
    e1.display();
    e1.display();
    e1.display();

    cout << "\n--- Creating e2 from e1 ---" << endl;
    Employee e2 = e1;
    cout << "e2's initial access count is: " << e2.getAccessCount() 
         << " (Proves custom logic happened, not just bitwise copy)" << endl;

    e2.display();

    return 0;
}
