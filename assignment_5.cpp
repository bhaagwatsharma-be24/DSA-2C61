//Q1
#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int data) {
        value = data;
        next = nullptr;
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void InsertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = nullptr;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void InsertAtEnd(int value) {
        if (head == nullptr) {
            InsertAtBeginning(value);
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            Node* newNode = new Node(value);
            temp->next = newNode;
            newNode->next = nullptr;
        }
    }

    void InsertAfterAdd(int check, int value) {
        Node* temp = head;
        int found = 0;
        while (temp) {
            if (temp->value == check) {
                found = 1;
                Node* newNode = new Node(value);
                newNode->next = temp->next;
                temp->next = newNode;
                break;
            } else {
                temp = temp->next;
            }
        }
        if (!found) {
            cout << "No such element " << check << " found!" << endl;
        }
    }

    void InsertBeforeAdd(int check, int value) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->value == check) {  // insert before head
            InsertAtBeginning(value);
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->value != check) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "No such element " << check << " found!" << endl;
        } else {
            Node* newNode = new Node(value);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteFromstart() {
        if (head) {
            Node* temp = head;
            head = temp->next;
            delete temp;
        } else {
            cout << "List is empty!" << endl;
        }
    }

    void deletefromend() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void deletespecific(int val) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->value == val) {
            Node* del = head;
            head = head->next;
            delete del;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->value != val) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "No such element " << val << " found!" << endl;
        } else {
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }
    }

    int displaypos(int val) {
        int count = 0;
        Node* temp = head;
        while (temp) {
            if (temp->value == val) {
                return count;
            } else {
                temp = temp->next;
                count++;
            }
        }
        return -1;
    }

    void display() {
        if (head == nullptr) {
            cout << "Empty list" << endl;
        } else {
            Node* temp = head;
            while (temp) {
                cout << temp->value << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};


int main() {
    LinkedList list;
    int choice, value, check;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a node\n";
        cout << "4. Insert before a node\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete specific node\n";
        cout << "8. Search node (position)\n";
        cout << "9. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.InsertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.InsertAtEnd(value);
            break;
        case 3:
            cout << "Enter value after which to insert: ";
            cin >> check;
            cout << "Enter new value: ";
            cin >> value;
            list.InsertAfterAdd(check, value);
            break;
        case 4:
            cout << "Enter value before which to insert: ";
            cin >> check;
            cout << "Enter new value: ";
            cin >> value;
            list.InsertBeforeAdd(check, value);
            break;
        case 5:
            list.deleteFromstart();
            break;
        case 6:
            list.deletefromend();
            break;
        case 7:
            cout << "Enter value to delete: ";
            cin >> value;
            list.deletespecific(value);
            break;
        case 8:
            cout << "Enter value to search: ";
            cin >> value;
            {
                int pos = list.displaypos(value);
                if (pos == -1)
                    cout << "Value not found!" << endl;
                else
                    cout << "Value found at position: " << pos << endl;
            }
            break;
        case 9:
            list.display();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}


//Q2
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
    Node* head;
public:
    LinkedList() { head = nullptr; }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) head = newNode;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    int deleteAllOccurrences(int key) {
        int count = 0;
        // Handle leading occurrences
        while (head && head->data == key) {
            Node* del = head;
            head = head->next;
            delete del;
            count++;
        }
        Node* temp = head;
        while (temp && temp->next) {
            if (temp->next->data == key) {
                Node* del = temp->next;
                temp->next = temp->next->next;
                delete del;
                count++;
            } else {
                temp = temp->next;
            }
        }
        return count;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(3);
    list.insert(1);

    cout << "Original List: ";
    list.display();

    int key = 1;
    int count = list.deleteAllOccurrences(key);

    cout << "Count: " << count << endl;
    cout << "Updated List: ";
    list.display();
    return 0;
}


//Q3
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
    Node* head;
public:
    LinkedList() { head = nullptr; }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) head = newNode;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    int findMiddle() {
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow ? slow->data : -1;
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);
    list.insert(7);

    cout << "Middle element: " << list.findMiddle() << endl;
    return 0;
}


//Q4
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
    Node* head;
public:
    LinkedList() { head = nullptr; }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) head = newNode;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);

    cout << "Original List: ";
    list.display();

    list.reverse();

    cout << "Reversed List: ";
    list.display();

    return 0;
}
