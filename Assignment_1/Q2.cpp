#include <iostream>
using namespace std;

int main() {
    int A[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> A[i];

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(A[i] == A[j]) {
                for(int k = j; k < n - 1; k++)
                    A[k] = A[k + 1];

                n--;        
                j--;   
            }
        }
    }

    cout << "Array after removing duplicates:\n";
    for(int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}
