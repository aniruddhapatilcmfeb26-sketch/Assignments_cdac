#include <iostream>
#include <iomanip> 
using namespace std;

int absolute(int n) {
    return (n < 0) ? -n : n;
}

int clamp(int val, int lo, int hi) {
    return (val < lo) ? lo : ((val > hi) ? hi : val);
}

int main() {

    cout << left << setw(10) << "val" 
         << setw(10) << "lo" 
         << setw(10) << "hi" 
         << setw(15) << "absolute(val)" 
         << setw(20) << "clamp(val,lo,hi)" << endl;

    cout << "------------------------------------------------------------" << endl;

    int v1 = -15, lo1 = -10, hi1 = 10;
    cout << left << setw(10) << v1 << setw(10) << lo1 << setw(10) << hi1 
         << setw(15) << absolute(v1) << setw(20) << clamp(v1, lo1, hi1) << endl;

    int v2 = 0, lo2 = -10, hi2 = 10;
    cout << left << setw(10) << v2 << setw(10) << lo2 << setw(10) << hi2 
         << setw(15) << absolute(v2) << setw(20) << clamp(v2, lo2, hi2) << endl;

    int v3 = 25, lo3 = -10, hi3 = 10;
    cout << left << setw(10) << v3 << setw(10) << lo3 << setw(10) << hi3 
         << setw(15) << absolute(v3) << setw(20) << clamp(v3, lo3, hi3) << endl;

    int v4 = -3, lo4 = 0, hi4 = 5;
    cout << left << setw(10) << v4 << setw(10) << lo4 << setw(10) << hi4 
         << setw(15) << absolute(v4) << setw(20) << clamp(v4, lo4, hi4) << endl;

    return 0;
}
