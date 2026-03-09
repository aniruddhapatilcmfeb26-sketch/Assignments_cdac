#include <iostream>

using namespace std;

class Number;

class Inspector {
public:
    void inspect(const Number& n);
};

class Number {
private:
    int value;

public:
    Number(int v = 0) : value(v) {}

    Number& operator++() {
        ++value;
        return *this;
    }

    Number operator++(int) {
        Number temp = *this; 
        value++;             
        return temp;         
    }

    Number& operator=(const Number& other) {
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }

    friend bool operator>(const Number& n1, const Number& n2);

    friend class Inspector;
};

bool operator>(const Number& n1, const Number& n2) {
    return n1.value > n2.value;
}

void Inspector::inspect(const Number& n) {

    cout << "Inspector reports the private value is: " << n.value << endl;
}

int main() {
    Number n1(10);
    Number n2(20);
    Inspector inspector;

    cout << "--- Initial Inspection ---" << endl;
    cout << "n1: "; inspector.inspect(n1);
    cout << "n2: "; inspector.inspect(n2);

    cout << "\n--- Comparison ---" << endl;
    if (n1 > n2) {
        cout << "n1 is greater than n2" << endl;
    } else {
        cout << "n1 is NOT greater than n2" << endl;
    }

    cout << "\n--- Pre-increment (++n1) ---" << endl;
    Number n3 = ++n1; 
    cout << "n1 after ++n1: "; inspector.inspect(n1);
    cout << "n3 value: "; inspector.inspect(n3);

    cout << "\n--- Post-increment (n2++) ---" << endl;
    Number n4 = n2++; 
    cout << "n2 after n2++: "; inspector.inspect(n2);
    cout << "n4 value (old n2): "; inspector.inspect(n4);

    cout << "\n--- Assignment Operator ---" << endl;
    n1 = n2; 
    cout << "n1 after n1 = n2: "; inspector.inspect(n1);

    return 0;
}
