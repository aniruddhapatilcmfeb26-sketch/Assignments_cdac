#include <iostream>

using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    int** data;

    void allocateMemory() {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols](); 
        }
    }

    void freeMemory() {
        if (data != nullptr) {
            for (int i = 0; i < rows; ++i) {
                delete[] data[i];
            }
            delete[] data;
            data = nullptr;
        }
    }

public:

    Matrix() : rows(0), cols(0), data(nullptr) {}

    Matrix(int r, int c) : rows(r), cols(c) {
        allocateMemory();
    }

    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        allocateMemory();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    Matrix& operator=(const Matrix& other) {
        if (this != &other) { 
            freeMemory();
            rows = other.rows;
            cols = other.cols;
            allocateMemory();
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    data[i][j] = other.data[i][j];
                }
            }
        }
        return *this;
    }

    ~Matrix() {
        freeMemory();
    }

    friend istream& operator>>(istream& in, Matrix& m) {
        cout << "Enter elements for " << m.rows << "x" << m.cols << " matrix:" << endl;
        for (int i = 0; i < m.rows; ++i) {
            for (int j = 0; j < m.cols; ++j) {
                in >> m.data[i][j];
            }
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, const Matrix& m) {
        for (int i = 0; i < m.rows; ++i) {
            out << "[ ";
            for (int j = 0; j < m.cols; ++j) {
                out << m.data[i][j] << " ";
            }
            out << "]" << endl;
        }
        return out;
    }

    Matrix operator+(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            cout << "Error: Matrices dimensions do not match for addition!" << endl;
            return Matrix(0, 0); 
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    bool operator==(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            return false;
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (this->data[i][j] != other.data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    int r = 2, c = 2;
    Matrix m1(r, c);
    Matrix m2(r, c);
    Matrix m3; 

    cout << "--- Input Matrices ---" << endl;
    cin >> m1;
    cin >> m2;

    cout << "\nMatrix 1:" << endl << m1;
    cout << "Matrix 2:" << endl << m2;

    cout << "\n--- Matrix Addition (m3 = m1 + m2) ---" << endl;
    m3 = m1 + m2;
    cout << "Matrix 3:" << endl << m3;

    cout << "\n--- Matrix Comparison ---" << endl;
    if (m1 == m2) {
        cout << "Matrix 1 and Matrix 2 are EQUAL." << endl;
    } else {
        cout << "Matrix 1 and Matrix 2 are NOT EQUAL." << endl;
    }

    return 0;
}
