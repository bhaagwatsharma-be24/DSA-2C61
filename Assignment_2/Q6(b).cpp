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

SparseMatrix add(SparseMatrix a, SparseMatrix b) {
    SparseMatrix c;
    if (a.rows != b.rows || a.cols != b.cols) {
        cout << "Matrices cannot be added!\n";
        c.numValues = 0;
        return c;
    }

    c.rows = a.rows;
    c.cols = a.cols;

    int i = 1, j = 1, k = 1;
    while (i <= a.numValues && j <= b.numValues) {
        if (a.data[i].row < b.data[j].row ||
           (a.data[i].row == b.data[j].row && a.data[i].col < b.data[j].col)) {
            c.data[k++] = a.data[i++];
        } else if (b.data[j].row < a.data[i].row ||
                  (b.data[j].row == a.data[i].row && b.data[j].col < a.data[i].col)) {
            c.data[k++] = b.data[j++];
        } else {
            int sum = a.data[i].value + b.data[j].value;
            if (sum != 0) {
                c.data[k].row = a.data[i].row;
                c.data[k].col = a.data[i].col;
                c.data[k].value = sum;
                k++;
            }
            i++; j++;
        }
    }

    while (i <= a.numValues) c.data[k++] = a.data[i++];
    while (j <= b.numValues) c.data[k++] = b.data[j++];

    c.numValues = k - 1;
    c.data[0] = {c.rows, c.cols, c.numValues};
    return c;
}

int main() {
    SparseMatrix a = {4, 4, 3, {
        {4,4,3}, {0,1,10}, {2,2,5}, {3,0,15}
    }};
    SparseMatrix b = {4, 4, 3, {
        {4,4,3}, {0,1,20}, {2,2,9}, {3,0,5}
    }};

    cout << "Matrix A:\n";
    printSparse(a);

    cout << "\nMatrix B:\n";
    printSparse(b);

    SparseMatrix c = add(a, b);

    cout << "\nResult (A + B):\n";
    printSparse(c);

    return 0;
}