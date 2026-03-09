#include <iostream>
#include <exception>

using namespace std;

class DivideByZero : public exception {
public:
    const char* what() const throw() {
        return "DivideByZero Exception: Denominator cannot be zero.";
    }
};

double divide(int numerator, int denominator) throw(DivideByZero) {
    if (denominator == 0) {
        throw DivideByZero();
    }
    return static_cast<double>(numerator) / denominator;
}

int main() {
    int num = 10;
    int den = 0;

    cout << "Attempting to divide " << num << " by " << den << endl;

    try {

        try {

            double result = divide(num, den);
            cout << "Result: " << result << endl;

        } catch (const DivideByZero& e) {

            cout << "Inside inner catch: Caught exception -> " << e.what() << endl;
            cout << "Rethrowing the exception to outer block..." << endl;
            throw; 
        }
    } catch (const DivideByZero& e) {

        cout << "Handled in outer catch: Exception finally resolved here." << endl;
    } catch (...) {

        cout << "Unknown exception caught in outer block." << endl;
    }

    return 0;
}
