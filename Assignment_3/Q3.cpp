#include <iostream>
using namespace std;

int main() {
    char exp[100];
    cin >> exp;

    char stackArr[100];
    int top = -1;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            stackArr[++top] = exp[i];     // push
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1) {
                cout << "Not Balanced";
                return 0;
            }

            char ch = stackArr[top--];    // pop

            if ((exp[i] == ')' && ch != '(') ||
                (exp[i] == '}' && ch != '{') ||
                (exp[i] == ']' && ch != '[')) {
                cout << "Not Balanced";
                return 0;
            }
        }
    }

    if (top == -1)
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}
