#include<iostream>
#include<string>
using namespace std;
Q1
int main(){
    int stack[100]={0};
    int top=-1;
    while(true){
        int x;
        cout << "implement stack operations \n1)push \n2)pop \n3)isEmpty \n4)isFull \n5)Display \n6)peek  " << endl;
        cin >> x;
        switch (x)
        {
        case 1:
            int entry;
            cout << "enter number to push:  "<< endl;
            cin >> entry;
            stack[++top]=entry;
            break;
        case 2:
            int poped;
            poped=stack[top--];
            cout << "element popped out: "<<poped;
            break;
        case 3:
            if (top <0){
                cout << "empty"<< endl;
            }
            break;
        case 4:
            if(top==100){
                cout << "full"<<endl;
            }
            break;
        case 5:
            for(int i=0;i<=top;i++){
                cout << stack[i] <<" ";
            }
            cout << endl;
            break;
        case 6:
            cout << stack[top];
            break;
        default:
            break;
        }
        int check;
        cout << "do you want to continue(1/0) "<< endl;
        cin >> check;
        if (check==0){
            break;
        }

    }
}
int main(){
    string x="DataStructure";
    char arr[100]={"0"};
    
    for(int i=0;i<x.length();i++){
        arr[i]=x[i];
    }
    for(int i= x.length()-1;i>=0;i--){
        x[x.length()-1-i]=arr[i];
    }
    cout << x;
}
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "()((a+b)*(a+c)*(b+c))/(a+b+c)";
    char st[200];
    int top = -1;

    for (char c : s) {
        if (c == '(') {
            st[++top] = '(';
        } else if (c == ')') {
            if (top == -1) {          
                cout << 0 << '\n';
                return 0;
            }
            --top;                   
        }
    }

    cout << (top == -1 ? 1 : 0) << '\n';  
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

#define MAX 200


int top = -1;
char st[MAX];

void push(char c) {
    if (top < MAX - 1) {
        st[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return st[top--];
    }
    return '\0'; 
}

char peek() {
    if (top >= 0) return st[top];
    return '\0';
}

bool isEmpty() {
    return (top == -1);
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPostfix(string infix) {
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) { 
            postfix += c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix += pop();
            }
            if (!isEmpty()) pop(); 
        }
        else if (isOperator(c)) {
            while (!isEmpty() && precedence(peek()) >= precedence(c)) {
                
                if (c == '^' && peek() == '^') break;
                postfix += pop();
            }
            push(c);
        }
    }

    
    while (!isEmpty()) {
        postfix += pop();
    }

    return postfix;
}

int main() {
    string infix = "((a+b)*(a+c)*(b+c))/(a+b+c)";
    cout << "Infix   : " << infix << endl;
    cout << "Postfix : " << infixToPostfix(infix) << endl;
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

bool isOperand(char ch) {
    return !(ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int main() {
    string expr = "234+*6-";
    int stack[100];   
    int top = -1;     

    for (char ch : expr) {
        if (isOperand(ch)) {
       
            stack[++top] = ch - '0';
        } else {
            
            int a = stack[top--];
            int b = stack[top--];
            int c;
            switch (ch) {
                case '+': c = b + a; break;
                case '-': c = b - a; break;
                case '*': c = b * a; break;
                case '/': c = b / a; break;
            }
            // push result back
            stack[++top] = c;
        }
    }

    cout << "Final result: " << stack[top] << endl;
    return 0;
}
