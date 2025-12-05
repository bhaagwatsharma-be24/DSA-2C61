#include <iostream>
using namespace std;

struct Node{
    int data;
    Node * next;
};

int countKey(Node*& head, int key) {
    int cnt = 0;

    while (head != nullptr && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cnt++;
    }

    Node* curr = head;
    while (curr != nullptr && curr->next != nullptr) {
        if (curr->next->data == key) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            cnt++;
        } 
        else {curr = curr->next;}
    }

    return cnt;
}

void display(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) cout << "->";
        head = head->next;
    }
    cout << endl;
}


int main(){
    Node* head = nullptr;
    Node* tail = nullptr;
    int n, val, key;

    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        Node* newNode = new Node{val, nullptr};
        if (head == nullptr) head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Enter key to remove: ";
    cin >> key;

    int cnt = countKey(head, key);
    cout << "Count: " << cnt << endl;
    cout << "Updated Linked List: ";
    display(head);

    return 0;
}