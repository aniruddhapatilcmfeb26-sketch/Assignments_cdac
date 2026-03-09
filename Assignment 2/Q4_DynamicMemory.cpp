#include <iostream>
#include <cstdlib> 

using namespace std;

int main() {
    cout << "--- Q4.1 Using new and delete[] ---" << endl;

    int* newArray = new int[5];

    cout << "Enter 5 integers for the 'new' array:" << endl;
    for (int i = 0; i < 5; ++i) {
        cin >> newArray[i];
    }

    cout << "Values in 'new' array: ";
    for (int i = 0; i < 5; ++i) {
        cout << newArray[i] << " ";
    }
    cout << endl;

    delete[] newArray;

    cout << "\n--- Q4.2 Using malloc and free ---" << endl;

    int* mallocArray = (int*)malloc(5 * sizeof(int));

    if (mallocArray == nullptr) {
        cout << "Memory allocation failed!" << endl;
        return 1;
    }

    cout << "Enter 5 integers for the 'malloc' array:" << endl;
    for (int i = 0; i < 5; ++i) {
        cin >> mallocArray[i];
    }

    cout << "Values in 'malloc' array: ";
    for (int i = 0; i < 5; ++i) {
        cout << mallocArray[i] << " ";
    }
    cout << endl;

    free(mallocArray);

    return 0;
}
