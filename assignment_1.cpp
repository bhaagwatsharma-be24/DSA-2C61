#include <iostream>
using namespace std;

char contChoice = 'y';
string menuOptions[] = {"create", "display", "insert", "remove", "search", "quit"};
int userOption;
int dataArray[100];
int arrLength = 0;

int main() {
    while (contChoice == 'y') {
        cout << "Select an operation by entering its number:" << endl;
        for (int i = 0; i < 6; i++) {
            cout << i + 1 << " : " << menuOptions[i] << endl;
        }
        cin >> userOption;

        if (userOption < 1 || userOption > 6) {
            cout << "Invalid input. Please try again." << endl;
        }
        else if (userOption == 1) {
            int newSize;
            cout << "Enter size of array to create: ";
            cin >> newSize;
            arrLength = newSize;
            for (int i = 0; i < newSize; i++) {
                int val;
                cout << "Enter value " << i + 1 << ": ";
                cin >> val;
                dataArray[i] = val;
            }
        }
        else if (userOption == 2) {
            cout << "Array elements: ";
            for (int i = 0; i < arrLength; i++) {
                cout << dataArray[i] << " ";
            }
            cout << endl;
        }
        else if (userOption == 3) {
            int newVal, pos;
            cout << "Enter position to insert: ";
            cin >> pos;
            cout << "Enter number to insert: ";
            cin >> newVal;
            for (int i = arrLength; i > pos; i--) {
                dataArray[i] = dataArray[i - 1];
            }
            dataArray[pos] = newVal;
            arrLength++;
        }
        else if (userOption == 4) {
            int pos;
            cout << "Enter position to remove: ";
            cin >> pos;
            for (int i = pos; i < arrLength; i++) {
                dataArray[i] = dataArray[i + 1];
            }
            arrLength--;
        }
        else if (userOption == 5) {
            int searchVal;
            cout << "Enter number to search: ";
            cin >> searchVal;
            bool found = false;
            for (int i = 0; i < arrLength; i++) {
                if (dataArray[i] == searchVal) {
                    cout << "Number found at position " << i + 1 << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Number not found." << endl;
            }
        }
        else if (userOption == 6) {
            cout << "Exiting program. Goodbye!" << endl;
            contChoice = 'n';
        }
    }

    
    int dupArray[] = {10, 20, 10, 30, 20, 40, 50, 30, 60};
    int dupSize = sizeof(dupArray) / sizeof(dupArray[0]);

    auto removeAt = [&](int index) {
        for (int i = index; i < dupSize; i++) {
            dupArray[i] = dupArray[i + 1];
        }
    };

    for (int i = 0; i < dupSize - 1; i++) {
        for (int j = i + 1; j < dupSize; j++) {
            if (dupArray[i] == dupArray[j]) {
                removeAt(j);
                dupSize--;
            }
        }
    }

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < dupSize; i++) {
        cout << dupArray[i] << " ";
    }
    cout << endl;

    
    int nums[] = {11, 22, 33, 44, 55};
    int len = sizeof(nums) / sizeof(nums[0]);
    for (int i = 0; i < len / 2; i++) {
        int temp = nums[i];
        nums[i] = nums[len - 1 - i];
        nums[len - 1 - i] = temp;
    }

    cout << "Reversed array: ";
    for (int i = 0; i < len; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    
    int mat[3][3] = {{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }

    cout << "Transpose of matrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    
    int arr3[3][3] = {{5, 7, 9}, {2, 4, 6}, {1, 3, 8}};
    int rowSums[3], colSums[3];

    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += arr3[i][j];
        }
        rowSums[i] = sum;
    }

    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += arr3[j][i];
        }
        colSums[i] = sum;
    }

    cout << "Row sums: ";
    for (int i = 0; i < 3; i++) {
        cout << rowSums[i] << " ";
    }
    cout << endl;

    cout << "Column sums: ";
    for (int i = 0; i < 3; i++) {
        cout << colSums[i] << " ";
    }
    cout << endl;

    return 0;
}
