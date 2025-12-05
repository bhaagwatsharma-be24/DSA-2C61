// a.

#include <iostream>
using namespace std;

int main() {
    int m; 
    cin >> m;
    int A[1000];
    for(int i=0;i<m;i++) cin >> A[i];
    for(int i=0;i<m;i++) if(A[i] != i+1) { cout << i+1; return 0; }
    cout << m+1;
    return 0;
}

// b.
#include <iostream>
using namespace std;

int main() {
    int m; cin >> m;
    int A[1000];
    for(int i=0;i<m;i++) cin >> A[i];

    int low = 0, high = m-1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(A[mid] == mid+1) low = mid + 1;
        else high = mid - 1;
    }
    cout << (low + 1);
    return 0;
}
