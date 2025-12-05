#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[100];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int start = 0, end = n - 1;

    while (start < end) {

        int minIndex = start;
        int maxIndex = start;

        
        for (int i = start; i <= end; i++) {
            if (a[i] < a[minIndex])
                minIndex = i;
            if (a[i] > a[maxIndex])
                maxIndex = i;
        }

       
        int temp = a[start];
        a[start] = a[minIndex];
        a[minIndex] = temp;

        
        if (maxIndex == start)
            maxIndex = minIndex;

       
        temp = a[end];
        a[end] = a[maxIndex];
        a[maxIndex] = temp;

        start++;
        end--;
    }

    
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
