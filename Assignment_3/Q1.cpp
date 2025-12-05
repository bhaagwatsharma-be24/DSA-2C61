#include <iostream>
using namespace std;

#define MAX 100

int stackArr[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1)
        cout << "Stack is Full\n";
    else
        stackArr[++top] = x;
}

void pop() {
    if (top == -1)
        cout << "Stack is Empty\n";
    else
        top--;
}

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX - 1;
}

void peek() {
    if (top == -1)
        cout << "Stack is Empty\n";
    else
        cout << "Top element: " << stackArr[top] << "\n";
}

void display() {
    if (top == -1)
        cout << "Stack is Empty\n";
    else {
        for (int i = top; i >= 0; i--)
            cout << stackArr[i] << " ";
        cout << "\n";
    }
}

int main() {
    int choice, val;

    do {
        cout << "\n1.Push\n2.Pop\n3.isEmpty\n4.isFull\n5.Display\n6.Peek\n7.Exit\n";
        cin >> choice;

        switch(choice) {
            case 1: cin >> val; push(val); break;
            case 2: pop(); break;
            case 3: cout << (isEmpty() ? "Yes\n" : "No\n"); break;
            case 4: cout << (isFull() ? "Yes\n" : "No\n"); break;
            case 5: display(); break;
            case 6: peek(); break;
        }
    } while(choice != 7);

    return 0;
}
