#include <iostream>
using namespace std;

void findMinMax(int a, int b, int c, int &minVal, int &maxVal) {

    minVal = a;
    if (b < minVal) minVal = b;
    if (c < minVal) minVal = c;

    maxVal = a;
    if (b > maxVal) maxVal = b;
    if (c > maxVal) maxVal = c;
}

int main() {
    int lo, hi;

    int num1 = 15, num2 = 8, num3 = 23;

    cout << "Numbers: " << num1 << ", " << num2 << ", " << num3 << endl;

    findMinMax(num1, num2, num3, lo, hi);

    cout << "Minimum value (lo): " << lo << endl;
    cout << "Maximum value (hi): " << hi << endl;

    return 0;
}
