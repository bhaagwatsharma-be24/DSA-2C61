#include <iostream>
using namespace std;

int A[100];
int n = 0;   

void createArr() {
    cout << "Enter number of elements: ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        cout << "A[" << i+1 << "] = ";
        cin >> A[i];
    }
}

void display() {
    if(n == 0) { cout << "Array is empty\n"; return; }
    for(int i = 0; i < n; i++) cout << A[i] << " ";
    cout << endl;
}

void insertElem() {
    int pos, val;
    cout << "Position: "; cin >> pos;
    cout << "Value: "; cin >> val;

    if(pos < 1 || pos > n+1) { cout << "Invalid\n"; return; }

    for(int i = n; i >= pos; i--) A[i] = A[i-1];
    A[pos-1] = val;
    n++;

    cout << "Inserted\n";
}

void deleteElem() {
    int pos;
    cout << "Position: "; cin >> pos;

    if(pos < 1 || pos > n) { cout << "Invalid\n"; return; }

    for(int i = pos-1; i < n-1; i++) A[i] = A[i+1];
    n--;

    cout << "Deleted\n";
}

void linearSearch() {
    int key;
    cout << "Search value: ";
    cin >> key;

    for(int i = 0; i < n; i++) {
        if(A[i] == key) {
            cout << "Found at position " << i+1 << endl;
            return;
        }
    }
    cout << "Not found\n";
}

int main() {
    int ch;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch(ch) {
            case 1: createArr(); break;
            case 2: display(); break;
            case 3: insertElem(); break;
            case 4: deleteElem(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid\n";
        }
    } while(ch != 6);

    return 0;
