#include <iostream>
#include <initializer_list>

using namespace std;

class Vector {
private:
    int* arr;
    int size;

public:

    Vector() : arr(nullptr), size(0) {}

    Vector(int s) : size(s) {
        arr = new int[size]();
    }

    Vector(initializer_list<int> list) {
        size = list.size();
        arr = new int[size];
        int i = 0;
        for (auto elem : list) {
            arr[i++] = elem;
        }
    }

    ~Vector() {
        if (arr != nullptr) {
            delete[] arr;
        }
    }

    int& operator[](int index) {
        if (index < 0 || index >= size) {
            cout << "Array index out of bounds! Returning first element safely." << endl;
            return arr[0]; 
        }
        return arr[index];
    }

    const int& operator[](int index) const {
        if (index < 0 || index >= size) {
            return arr[0];
        }
        return arr[index];
    }

    int operator()() const {
        int sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += arr[i];
        }
        return sum;
    }
};

int main() {

    Vector v = {10, 20, 30, 40};

    cout << "Initial sum of vector {10, 20, 30, 40}: " << v() << endl;

    v[2] = 50;
    cout << "Modified v[2] to 50." << endl;

    cout << "New sum: v() = " << v() << endl;

    return 0;
}
