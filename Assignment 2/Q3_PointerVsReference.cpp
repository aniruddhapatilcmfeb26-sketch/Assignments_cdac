#include <iostream>

using namespace std;

int main() {
    int value = 100;

    int* ptr = &value;

    int& ref = value;

    cout << "Initial Value: " << value << endl << endl;

    *ptr = 200;
    cout << "Value after modification via pointer (*ptr = 200): " << value << endl;

    ref = 300;
    cout << "Value after modification via reference (ref = 300):  " << value << endl;

    return 0;
}
