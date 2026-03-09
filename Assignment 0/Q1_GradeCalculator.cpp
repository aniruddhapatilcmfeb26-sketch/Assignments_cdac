#include <iostream>
using namespace std;

int main() {
    float sub1 = 80.5, sub2 = 72.0, sub3 = 68.5, sub4 = 91.0, sub5 = 55.5;

    float total = sub1 + sub2 + sub3 + sub4 + sub5;
    float percentage = (total / 500.0) * 100.0;

    char grade = (percentage >= 75) ? 'A' :
                 (percentage >= 60) ? 'B' :
                 (percentage >= 45) ? 'C' : 'F'; 

    cout << "--- Marks ---" << endl;
    cout << "Subject 1: " << sub1 << endl;
    cout << "Subject 2: " << sub2 << endl;
    cout << "Subject 3: " << sub3 << endl;
    cout << "Subject 4: " << sub4 << endl;
    cout << "Subject 5: " << sub5 << endl;
    cout << "-------------" << endl;

    cout << "Total Marks: " << total << " / 500" << endl;
    cout << "Percentage: " << percentage << "%" << endl;

    cout << "Grade: ";
    if (grade == 'F') {
        cout << "Fail" << endl;
    } else {
        cout << grade << endl;
    }

    return 0;
}
