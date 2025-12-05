#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *prev, *next;
    Node(char c) : data(c), prev(nullptr), next(nullptr) {}
};

class DLL {
    Node *head, *tail;
public:
    DLL() : head(nullptr), tail(nullptr) {}

    void insertEnd(char c) {
        Node *n = new Node(c);
        if (!head) {
            head = tail = n;
            return;
        }
        tail->next = n;
        n->prev = tail;
        tail = n;
    }

    bool isPalindrome() {
        if (!head) return true;
        Node *l = head, *r = tail;
        while (l != r && l->prev != r) {
            if (l->data != r->data) return false;
            l = l->next;
            r = r->prev;
        }
        return true;
    }
};

int main() {
    DLL d;
    string s = "LEVEL";
    for (char c : s) d.insertEnd(c);
    cout << (d.isPalindrome() ? "True\n" : "False\n");

    DLL e;
    string t = "HELLO";
    for (char c : t) e.insertEnd(c);
    cout << (e.isPalindrome() ? "True\n" : "False\n");

    return 0;
}