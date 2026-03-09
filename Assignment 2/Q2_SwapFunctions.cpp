#include <iostream>

using namespace std;

void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapByAddress(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapByReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;

    x = 10; y = 20;
    cout << "Before swapByValue - x: " << x << ", y: " << y << endl;
    swapByValue(x, y);
    cout << "After swapByValue  - x: " << x << ", y: " << y << " (No change)\n" << endl;

    x = 10; y = 20;
    cout << "Before swapByAddress - x: " << x << ", y: " << y << endl;
    swapByAddress(&x, &y);
    cout << "After swapByAddress  - x: " << x << ", y: " << y << " (Swapped)\n" << endl;

    x = 10; y = 20;
    cout << "Before swapByReference - x: " << x << ", y: " << y << endl;
    swapByReference(x, y);
    cout << "After swapByReference  - x: " << x << ", y: " << y << " (Swapped)\n" << endl;

    return 0;
}
