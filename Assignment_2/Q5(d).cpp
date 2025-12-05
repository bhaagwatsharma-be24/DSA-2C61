#include <iostream>
using namespace std;

class UpperTriangular {
    int n;
    int *A;
public:
    UpperTriangular(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    void set(int i, int j, int x) {
        if (i <= j) A[i*n - (i*(i-1))/2 + (j - i)] = x;
    }
    int get(int i, int j) {
        if (i <= j) return A[i*n - (i*(i-1))/2 + (j - i)];
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
    UpperTriangular u(4);
    u.set(0,0,5); u.set(0,1,8); u.set(0,2,3); u.set(0,3,7);
    u.set(1,1,6); u.set(1,2,9); u.set(1,3,4);
    u.set(2,2,11); u.set(2,3,2);
    u.set(3,3,10);
    u.display();
}