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

SparseMatrix transpose(SparseMatrix s) {
    SparseMatrix result;
    result.rows = s.cols;
    result.cols = s.rows;
    result.numValues = s.numValues;

    result.data[0] = {s.cols, s.rows, s.numValues};

    int k = 1;
    for (int i = 0; i < s.cols; i++) {
        for (int j = 1; j <= s.numValues; j++) {
            if (s.data[j].col == i) {
                result.data[k].row = s.data[j].col;
                result.data[k].col = s.data[j].row;
                result.data[k].value = s.data[j].value;
                k++;
            }
        }
    }
    return result;
}

int main() {
    SparseMatrix s = {4, 4, 5, {
        {4,4,5}, {0,2,8}, {1,3,23}, {2,2,9}, {3,0,20}, {3,1,25}
    }};

    cout << "Original Matrix:\n";
    printSparse(s);

    SparseMatrix t = transpose(s);

    cout << "\nTranspose Matrix:\n";
    printSparse(t);

    return 0;
}


    