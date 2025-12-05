#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int v){ data = v; next = NULL; }
};

bool isCircular(Node *head) {
    if (!head) return true;
    Node *temp = head->next;
    while (temp != NULL && temp != head)
        temp = temp->next;
    return (temp == head);
}

int main() {
    Node *head = new Node(2);
    head->next = new Node(4);
    head->next->next = new Node(6);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(5);
    
    // Make it circular
    head->next->next->next->next->next = head;

    cout << (isCircular(head) ? "True" : "False");
}