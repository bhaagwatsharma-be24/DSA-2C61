#include <iostream>
using namespace std;

struct Triple {
    int row, col, value;
};

struct SparseMatrix {
    int rows, cols, numValues;
    Triple data[50];
};

void printSparse(SparseMatrix s) {
    cout << "Row Col Value\n";
    for (int i = 0; i <= s.numValues; i++) {
        cout << s.data[i].row << " " 
             << s.data[i].col << " " 
             << s.data[i].value << "\n";
    }
}

SparseMatrix multiply(SparseMatrix a, SparseMatrix b) {
    SparseMatrix c;
    if (a.cols != b.rows) {
        cout << "Multiplication not possible!\n";
        c.numValues = 0;
        return c;
    }

    c.rows = a.rows;
    c.cols = b.cols;
    int k = 1;

    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            int sum = 0;
            for (int x = 1; x <= a.numValues; x++) {
                if (a.data[x].row == i) {
                    for (int y = 1; y <= b.numValues; y++) {
                        if (b.data[y].row == a.data[x].col && b.data[y].col == j) {
                            sum += a.data[x].value * b.data[y].value;
                        }
                    }
                }
            }
            if (sum != 0) {
                c.data[k++] = {i, j, sum};
            }
        }
    }

    c.numValues = k - 1;
    c.data[0] = {c.rows, c.cols, c.numValues};
    return c;
}

int main() {
    SparseMatrix a = {4, 4, 3, {
        {4,4,3}, {0,1,10}, {0,3,12}, {2,2,5}
    }};
    SparseMatrix b = {4, 4, 3, {
        {4,4,3}, {0,3,20}, {1,3,25}, {2,2,9}
    }};

    cout << "Matrix A:\n";
    printSparse(a);

    cout << "\nMatrix B:\n";
    printSparse(b);

    SparseMatrix c = multiply(a, b);

    cout << "\nResult (A * B):\n";
    printSparse(c);

    return 0;
}