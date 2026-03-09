#include <iostream>
using namespace std;

int main() {

    int x = 10;
    int y = 20;
    int z = 30;

    int* px = &x;
    int* py = &y;
    int* pz = &z;

    cout << "--- Before Swap ---" << endl;
    cout << "Values: x = " << *px << ", y = " << *py << ", z = " << *pz << endl;
    cout << "Addresses: px = " << px << ", py = " << py << ", pz = " << pz << endl;

    int temp = *px;
    *px = *pz;
    *pz = temp;

    cout << "\n--- After Swap ---" << endl;
    cout << "Values: x = " << *px << ", y = " << *py << ", z = " << *pz << endl;
    cout << "Addresses: px = " << px << ", py = " << py << ", pz = " << pz << endl;

    return 0;
}
