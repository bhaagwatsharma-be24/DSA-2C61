#include <iostream>
using namespace std;

int main() {

    // a) Reverse Array
    int A[100], n;
    cout << "Enter size: ";
    cin >> n;
    for(int i = 0; i < n; i++) cin >> A[i];

    int i = 0, j = n - 1;
    while(i < j) {
        int t = A[i];
        A[i] = A[j];
        A[j] = t;
        i++; j--;
    }

    cout << "Reversed Array: ";
    for(int i = 0; i < n; i++) cout << A[i] << " ";
    cout << "\n";


    // b) Matrix Multiplication
    int r1, c1, r2, c2;
    int X[10][10], Y[10][10], Z[10][10];

    cout << "Enter r1 c1: ";
    cin >> r1 >> c1;
    for(int i=0;i<r1;i++)
        for(int j=0;j<c1;j++)
            cin >> X[i][j];

    cout << "Enter r2 c2: ";
    cin >> r2 >> c2;
    for(int i=0;i<r2;i++)
        for(int j=0;j<c2;j++)
            cin >> Y[i][j];

    if(c1 != r2){ cout << "Not possible"; return 0; }

    for(int i=0;i<r1;i++)
        for(int j=0;j<c2;j++) {
            Z[i][j] = 0;
            for(int k=0;k<c1;k++)
                Z[i][j] += X[i][k] * Y[k][j];
        }

    cout << "Product:\n";
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++)
            cout << Z[i][j] << " ";
        cout << endl;
    }


    // c) Transpose
    int T[10][10];
    for(int i=0;i<r1;i++)
        for(int j=0;j<c1;j++)
            T[j][i] = X[i][j];

    cout << "Transpose of X:\n";
    for(int i=0;i<c1;i++){
        for(int j=0;j<r1;j++)
            cout << T[i][j] << " ";
        cout << endl;
    }

    return 0;
}
