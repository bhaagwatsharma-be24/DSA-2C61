#include <iostream>
using namespace std;

int main() {
    int A[100], n, key;

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter sorted elements:\n";
    for(int i = 0; i < n; i++)
        cin >> A[i];

    cout << "Enter element to search: ";
    cin >> key;

    int low = 0, high = n - 1, mid;
    int found = -1;

    while(low <= high) {
        mid = (low + high) / 2;

        if(A[mid] == key) {
            found = mid;
            break;
        }
        else if(key < A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if(found == -1)
        cout << "Not found";
    else
        cout << "Found at position " << found + 1;

    return 0;
}
