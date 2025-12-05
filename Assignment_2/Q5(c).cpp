#include <iostream>
using namespace std;

class LowerTriangular {
    int n;
    int *A;
public:
    LowerTriangular(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    void set(int i, int j, int x) {
        if (i >= j) A[i*(i+1)/2 + j] = x;
    }
    int get(int i, int j) {
        if (i >= j) return A[i*(i+1)/2 + j];
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
    LowerTriangular l(4);
    l.set(0,0,5);
    l.set(1,0,8); l.set(1,1,6);
    l.set(2,0,3); l.set(2,1,7); l.set(2,2,9);
    l.set(3,0,4); l.set(3,1,1); l.set(3,2,2); l.set(3,3,10);
    l.display();
}