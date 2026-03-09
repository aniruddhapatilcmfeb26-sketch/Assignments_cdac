#include <iostream>

using namespace std;

class Box {
private:
    int length;
    int width;
    int height;

public:

    Box(int l, int w, int h) {
        length = l;
        width = w;
        height = h;
        cout << "Box created using Parameterized Constructor!" << endl;
    }

    void setDimensions(int length, int width, int height) {
        this->length = length;
        this->width = width;
        this->height = height;
        cout << "Dimensions updated using setDimensions(assignment)!" << endl;
    }

    int volume() const {
        return length * width * height;
    }
};

int main() {

    Box b1(10, 5, 2);
    cout << "Volume of b1: " << b1.volume() << endl << endl;

    b1.setDimensions(20, 10, 5);
    cout << "Volume of b1 after update: " << b1.volume() << endl;

    return 0;
}
