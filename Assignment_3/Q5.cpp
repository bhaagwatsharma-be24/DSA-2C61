#include <iostream>
#include <cstring>
using namespace std;

int main() {

    // Postfix expression tokens
    // Same as: 1 3 - 4 *
    char expr[5][10] = {"1", "3", "-", "4", "*"};
    int n = 5;

    int stackArr[100];
    int top = -1;

    for (int i = 0; i < n; i++) {

        // If the token is an operator
        if (strcmp(expr[i], "+") == 0 ||
            strcmp(expr[i], "-") == 0 ||
            strcmp(expr[i], "*") == 0 ||
            strcmp(expr[i], "/") == 0) {

            int a = stackArr[top--];   // first popped
            int b = stackArr[top--];   // second popped
            int res;

            if (strcmp(expr[i], "+") == 0)
                res = b + a;
            else if (strcmp(expr[i], "-") == 0)
                res = b - a;
            else if (strcmp(expr[i], "*") == 0)
                res = b * a;
            else
                res = b / a;

            stackArr[++top] = res;   // push result back
        }

        // If the token is a number
        else {
            int num = 0;

            // Convert string to integer manually
            for (int j = 0; expr[i][j] != '\0'; j++) {
                num = num * 10 + (expr[i][j] - '0');
            }

            stackArr[++top] = num;
        }
    }

    cout << stackArr[top]; // Final result

    return 0;
}
