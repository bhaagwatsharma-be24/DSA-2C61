#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,2,2,3,4,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    int count = 0;

    for(int i = 0; i < n; i++) {
        bool seenBefore = false;

        
        for(int j = 0; j < i; j++) {
            if(arr[i] == arr[j]) {
                seenBefore = true;
                break;
            }
        }

        if(!seenBefore)
            count++;
    }

    cout << "Distinct Elements: " << count;
}
