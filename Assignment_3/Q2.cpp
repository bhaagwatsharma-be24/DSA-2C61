#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[100];
    cin >> str;

    char stackArr[100];
    int top = -1;

    
    for (int i = 0; str[i] != '\0'; i++)
        stackArr[++top] = str[i];

    
    while (top != -1)
        cout << stackArr[top--];

    return 0;
}
