#include <iostream>
using namespace std;

class TriDiagonal {
    int n;
    int *A; // size 3n-2
public:
    TriDiagonal(int n) {
        this->n = n;
        A = new int[3*n - 2];
    }
    void set(int i, int j, int x) {
        if (i - j == 0)       A[n-1 + i] = x;  // main diagonal
        else if (i - j == 1)  A[i-1] = x;      // lower diagonal
        else if (j - i == 1)  A[2*n - 1 + i] = x; // upper diagonal
    }
    int get(int i, int j) {
        if (i - j == 0)       return A[n-1 + i];
        else if (i - j == 1)  return A[i-1];
        else if (j - i == 1)  return A[2*n - 1 + i];
        return 0;
    }
    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    TriDiagonal t(4);
    t.set(0,0,5); t.set(0,1,8);
    t.set(1,0,7); t.set(1,1,10); t.set(1,2,9);
    t.set(2,1,6); t.set(2,2,11); t.set(2,3,12);
    t.set(3,2,15); t.set(3,3,20);
    t.display();
}