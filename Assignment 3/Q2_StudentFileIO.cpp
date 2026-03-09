#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student {
private:
    int roll;
    string name;
    float marks;

public:

    Student() : roll(0), name(""), marks(0.0f) {}

    Student(int r, string n, float m) : roll(r), name(n), marks(m) {}

    ~Student() {
        cout << "Destroying student " << name << " (" << roll << ")" << "..." << endl;
    }

    void setDetails(int r, string n, float m) {
        roll = r; name = n; marks = m;
    }

    string toDataString() const {
        return to_string(roll) + "," + name + "," + to_string(marks);
    }

    void print() const {
        cout << "Roll: " << roll << ", Name: " << name << ", Marks: " << marks << endl;
    }
};

int main() {
    cout << "--- 1. Creating Array ---" << endl;

    Student students[3];
    students[0].setDetails(101, "Alice", 85.5f);
    students[1].setDetails(102, "Bob", 76.0f);
    students[2].setDetails(103, "Charlie", 92.5f);

    cout << "\n--- 2. Writing to File ---" << endl;

    ofstream outFile("students.txt");
    if (outFile.is_open()) {
        for (int i = 0; i < 3; i++) {
            outFile << students[i].toDataString() << endl;
        }
        outFile.close();
        cout << "Successfully wrote to students.txt" << endl;
    } else {
        cout << "Unable to open file for writing!" << endl;
    }

    cout << "\n--- 3. Reading from File ---" << endl;

    ifstream inFile("students.txt");
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            cout << "Read from file: " << line << endl;
        }
        inFile.close();
    } else {
        cout << "Unable to open file for reading!" << endl;
    }

    cout << "\n--- Exiting scope (Destructors will be called now) ---" << endl;
    return 0;
}
