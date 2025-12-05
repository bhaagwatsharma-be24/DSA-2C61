#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next, *prev;
    Node(int v) {
        data = v;
        next = prev = NULL;
    }
};

class DLL {
    Node *head;
public:
    DLL() { head = NULL; }

    void insert(int v) {
        Node *n = new Node(v);
        if (!head) {
            head = n;
            return;
        }
        Node *t = head;
        while (t->next)
            t = t->next;
        t->next = n;
        n->prev = t;
    }

    int size() {
        int count = 0;
        Node *t = head;
        while (t) {
            count++;
            t = t->next;
        }
        return count;
    }
};

struct C_Node {
    int data;
    C_Node *next;
    C_Node(int v) {
        data = v;
        next = NULL;
    }
};

class CLL {
    C_Node *tail;
public:
    CLL() { tail = NULL; }

    void insert(int v) {
        C_Node *n = new C_Node(v);
        if (!tail) {
            tail = n;
            tail->next = tail;
            return;
        }
        n->next = tail->next;
        tail->next = n;
        tail = n;
    }

    int size() {
        if (!tail)
            return 0;
        int count = 0;
        C_Node *t = tail->next;  
        do {
            count++;
            t = t->next;
        } while (t != tail->next);
        return count;
    }
};

int main() {
    DLL d;
    d.insert(1);
    d.insert(2);
    d.insert(3);
    cout << "Size of Doubly Linked List: " << d.size() << endl;

    CLL c;
    c.insert(10);
    c.insert(20);
    c.insert(30);
    cout << "Size of Circular Linked List: " << c.size() << endl;

    return 0;
}