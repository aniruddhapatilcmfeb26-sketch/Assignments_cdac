#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    char* str;

public:

    String() {
        str = new char[1];
        str[0] = '\0';
    }

    String(const char* val) {
        if (val) {
            str = new char[strlen(val) + 1];
            strcpy(str, val);
        } else {
            str = new char[1];
            str[0] = '\0';
        }
    }

    String(const String& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str; 
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    String operator+(const String& other) {

        int length = strlen(str) + strlen(other.str);

        char* newStr = new char[length + 1];

        strcpy(newStr, str);
        strcat(newStr, other.str);

        String result(newStr);
        delete[] newStr; 

        return result;
    }

    ~String() {
        delete[] str;
    }

    friend ostream& operator<<(ostream& os, const String& obj) {
        os << obj.str;
        return os;
    }

    friend istream& operator>>(istream& is, String& obj) {
        char buffer[1000];
        is >> buffer; 
        obj = String(buffer); 
        return is;
    }
};

int main() {
    String s1, s2, s3;

    cout << "Enter first string (no spaces): ";
    cin >> s1;

    cout << "Enter second string (no spaces): ";
    cin >> s2;

    s3 = s1 + s2;

    cout << "\n--- String Results ---" << endl;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3 (Concatenated): " << s3 << endl;

    return 0; 
}
