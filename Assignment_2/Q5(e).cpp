#include <iostream>
using namespace std;

class Symmetric {
    int n;
    int *A;
public:
    Symmetric(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    void set(int i, int j, int x) {
        if (i >= j) A[i*(i+1)/2 + j] = x;
        else A[j*(j+1)/2 + i] = x;  // symmetric property
    }
    int get(int i, int j) {
        if (i >= j) return A[i*(i+1)/2 + j];
        return A[j*(j+1)/2 + i];
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
    Symmetric s(4);
    s.set(0,0,5);
    s.set(1,0,8); s.set(1,1,6);
    s.set(2,0,3); s.set(2,1,7); s.set(2,2,9);
    s.set(3,0,4); s.set(3,1,1); s.set(3,2,2); s.set(3,3,10);
    s.display();
}