#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float marks;

public:

    Student() {
        rollNo = 0;
        name = "Unknown";
        marks = 0.0f;
    }

    Student(int r, string n, float m) {
        rollNo = r;
        name = n;
        marks = m;
    }

    Student(int rollNo, string name) {
        this->rollNo = rollNo;
        this->name = name;
        this->marks = 0.0f; 
    }

    void printDetails() const {
        cout << "Roll No: " << rollNo << " | Name: " << name << " | Marks: " << marks << endl;
    }
};

int main() {

    Student s1;
    cout << "Object 1 (Default):" << endl;
    s1.printDetails();

    Student s2(101, "Alice", 95.5f); 
    Student s3(102, "Bob");          

    cout << "\nObject 2 (Parameterized):" << endl;
    s2.printDetails();

    cout << "\nObject 3 (Parameterized with `this->`):" << endl;
    s3.printDetails();

    return 0;
}
