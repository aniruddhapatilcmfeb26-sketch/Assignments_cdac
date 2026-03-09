#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float marks;
    char grade;

public:

    Student() : name(""), rollNumber(0), marks(0.0), grade('F') {}

    void setName(const string& n) { name = n; }
    void setRollNumber(int r) { rollNumber = r; }
    void setMarks(float m) { marks = m; }

    string getName() const { return name; }
    int getRollNumber() const { return rollNumber; }
    float getMarks() const { return marks; }
    char getGrade() const { return grade; }

    void calculateGrade() {
        if (marks >= 90 && marks <= 100)
            grade = 'A';
        else if (marks >= 80 && marks < 90)
            grade = 'B';
        else if (marks >= 70 && marks < 80)
            grade = 'C';
        else if (marks >= 60 && marks < 70)
            grade = 'D';
        else
            grade = 'F';
    }

    void acceptInformation() {
        cout << "Enter Student Name: ";
        cin.ignore(); 
        getline(cin, name);

        cout << "Enter Roll Number: ";
        cin >> rollNumber;

        cout << "Enter Marks: ";
        cin >> marks;

        calculateGrade();
    }

    void displayInformation() const {
        cout << "\n--- Student Details ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: " << marks << endl;
        cout << "Grade: " << grade << endl;
        cout << "-----------------------" << endl;
    }
};

int main() {
    Student s;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Accept Information\n";
        cout << "2. Display Information\n";
        cout << "3. Calculate Grade\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                s.acceptInformation();
                break;
            case 2:
                s.displayInformation();
                break;
            case 3:
                s.calculateGrade();
                cout << "Grade calculated successfully!" << endl;
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
