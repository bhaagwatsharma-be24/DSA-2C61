#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) { data = x; next = nullptr; }
};

Node* head = nullptr;

void insertBeginning(int x) {
    Node* n = new Node(x);
    n->next = head;
    head = n;
}

void insertEnd(int x) {
    Node* n = new Node(x);
    if (head == nullptr) { head = n; return; }
    Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
}

void insertAfter(int key, int x) {
    Node* t = head;
    while (t && t->data != key) t = t->next;
    if (t == nullptr) return; // key not found
    Node* n = new Node(x);
    n->next = t->next;
    t->next = n;
}

void insertBefore(int key, int x) {
    if (head == nullptr) return;
    if (head->data == key) { insertBeginning(x); return; }
    Node* prev = nullptr;
    Node* t = head;
    while (t && t->data != key) { prev = t; t = t->next; }
    if (t == nullptr) return; // key not found
    Node* n = new Node(x);
    prev->next = n;
    n->next = t;
}

void deleteBeginning() {
    if (head == nullptr) return;
    Node* t = head;
    head = head->next;
    delete t;
}

void deleteEnd() {
    if (head == nullptr) return;
    if (head->next == nullptr) { delete head; head = nullptr; return; }
    Node* prev = nullptr;
    Node* t = head;
    while (t->next) { prev = t; t = t->next; }
    prev->next = nullptr;
    delete t;
}

void deleteNode(int key) {
    if (head == nullptr) return;
    if (head->data == key) { deleteBeginning(); return; }
    Node* prev = nullptr;
    Node* t = head;
    while (t && t->data != key) { prev = t; t = t->next; }
    if (t == nullptr) return; // not found
    prev->next = t->next;
    delete t;
}

int searchNode(int key) {
    Node* t = head;
    int pos = 1;
    while (t) {
        if (t->data == key) return pos;
        t = t->next;
        pos++;
    }
    return -1; // not found
}

void display() {
    if (head == nullptr) { cout << "List empty\n"; return; }
    Node* t = head;
    while (t) {
        cout << t->data;
        if (t->next) cout << " -> ";
        t = t->next;
    }
    cout << "\n";
}

int main() {
    int choice, x, key;
    do {
        cout << "\n1.Insert at beginning\n2.Insert at end\n3.Insert before a value\n4.Insert after a value\n";
        cout << "5.Delete from beginning\n6.Delete from end\n7.Delete a specific node\n8.Search node\n9.Display\n10.Exit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> x;
                insertBeginning(x);
                break;
            case 2:
                cin >> x;
                insertEnd(x);
                break;
            case 3:
                cin >> key >> x; // key = existing value, x = new node
                insertBefore(key, x);
                break;
            case 4:
                cin >> key >> x; // key = existing value, x = new node
                insertAfter(key, x);
                break;
            case 5:
                deleteBeginning();
                break;
            case 6:
                deleteEnd();
                break;
            case 7:
                cin >> key; // value to delete
                deleteNode(key);
                break;
            case 8: {
                cin >> key;
                int pos = searchNode(key);
                if (pos == -1) cout << "Not found\n"; else cout << "Position: " << pos << "\n";
                break;
            }
            case 9:
                display();
                break;
            case 10:
                break;
            default:
                cout << "Invalid\n";
        }
    } while (choice != 10);
    return 0;
}
