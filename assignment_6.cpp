#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* next;
    Node* prev;

    Node(int data){
        value=data;
        next=nullptr;
        prev=nullptr;
    }
};
class CircularLinkedList{
    Node* head;
    Node *tail;
    public:
    CircularLinkedList(){
        head=nullptr;
        tail=nullptr;
    }
    void insertatbegin(int n){
        Node* newnode= new Node(n);
        if(head==tail && head==nullptr){
            head=newnode;
            tail=newnode;
            head->next=tail;
            tail->next=head;
            head->prev=tail;
            tail->prev=head;
        }
        else{
            newnode->next=head;
            newnode->prev=tail;
            head->prev=newnode;
            head=newnode;
            // head->prev=tail;
            tail->next=head;
        }
    }
    void insertatend(int n){
        Node* newnode= new Node(n);
        if(head==tail && head==nullptr){
            head=newnode;
            tail=newnode;
            head->next=tail;
            tail->next=head;
            head->prev=tail;
            tail->prev=head;
        }
        else{
            newnode->next=head;
            newnode->prev=tail;
            tail->next=newnode;
            head->prev=newnode;
            tail=newnode;
        }
    }
    void insertatspecefic(int n,int x){
        Node *newnode= new Node(n);
        Node * temp= head;
        if(head==tail && head==nullptr){
            cout << "empty \n";
            return;
        }
        while(temp->next!=head && temp->value!=x){
            temp=temp->next;
        }
        if(temp->next==head){
            if(tail->value==x){
                insertatend(n);
            }
        }
        else{
            newnode->next=temp->next;
            newnode->prev=temp;
            newnode->next->prev=newnode;
            temp->next=newnode;

        }
    }
    void deletenode(int x){
        if(head==tail && head==nullptr){
            cout << "empty \n";
            return;
        }
        Node *temp=head;
        if(head->value==x){
            tail->next=head->next;
            head->next->prev=tail;
            head=head->next;
            delete temp;
        }
        else{
            while(temp->next!=head && temp->value!=x){
                temp=temp->next;
            }
            if(temp->next==head){
                if(tail->value==x){
                    Node *yo=tail;
                    tail->prev->next=head;
                    head->prev=tail->prev;
                    tail=tail->prev;
                    delete yo;
                }
            }
            else{
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                delete temp;
            }

        }
    }
    int search(int x) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return -1;
    }

    int count = 1;
    Node* temp1 = head;
    Node* temp2 = tail;
    bool found = false;

    while (temp1 != temp2 && temp1->next != temp2) {
        if (temp1->value == x) {
            cout << "It is found at " << count << " position \n";
            found = true;
            break;
        }
        else if (temp2->value == x) {
            cout << "It is found at " << -count << " position ";
            found = true;
            break;
        }
        temp1 = temp1->next;
        temp2 = temp2->prev;
        count++;
    }

    
    if (!found) {
        if (temp1->value == x) {
            cout << "It is found at " << count << " position \n";
            found = true;
        }
        else if (temp2->value == x) {
            cout << "It is found at " << -count << " position \n";
            found = true;
        }
    }

    if (!found)
        cout << "Not found\n";

    return found ? count : -1;
}

    void display(){
        if(head==tail && head==nullptr){
            cout << "empty \n";
            return;
        }
        else{
            Node* temp=head;
            while(temp->next!=head){
                cout << temp->value << " => ";
                temp=temp->next;
            }
            cout << tail->value << endl ;
        }
    }
    void display_head(){
        if(head==tail && head==nullptr){
            cout << "empty \n";
            return;
        }
        else{
            Node* temp=head;
            while(temp->next!=head){
                cout << temp->value << " => ";
                temp=temp->next;
            }
            cout << tail->value << " => "<< head->value << endl ;
        }
    }
    void displayreverse(){
        if(head==tail && head==nullptr){
            cout << "empty \n";
            return;
        }
        else{
            Node* temp=tail;
            while(temp->prev!=tail){
                cout << temp->value << " => ";
                temp=temp->prev;
            }
            cout << head->value << endl ;
        }
    }
    int size(){
        if(head==tail && head==nullptr){
            cout << "empty \n";
            return 0;
        }
    int count = 0;
    Node* temp1 = head;
    Node* temp2 = tail;

    while (temp1 != temp2 && temp1->next != temp2) {
        temp1 = temp1->next;
        temp2 = temp2->prev;
        count=count+2;
    }
    if(temp1==temp2){
        return ++count;
    }
    else{
        count+=2;
        return count;
    }
    }
    bool iscircular(){
        Node *slow=head;
        Node *fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};
class DoublyLinkedList{
    Node* head;
    Node *tail;
    public:
    DoublyLinkedList(){
        head=nullptr;
        tail=nullptr;
    }
    void insertatbegin(int n){
        Node* newnode= new Node(n);
        if(head==tail && head==nullptr){
            head=newnode;
            tail=newnode;
            head->next=tail;
            tail->next=nullptr;
            head->prev=nullptr;
            tail->prev=head;
        }
        else{
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
    }
    void insertatend(int n){
        Node* newnode= new Node(n);
        if(head==tail && head==nullptr){
            insertatbegin(n);
        }
        else{
            newnode->next=nullptr;
            newnode->prev=tail;
            tail->next=newnode;
            tail=newnode;
        }
    }
    void insertatspecefic(int n,int x){
        Node *newnode= new Node(n);
        Node * temp= head;
        if(head==tail && head==nullptr){
            cout << "empty \n";
            return;
        }
        while(temp->next!=head && temp->value!=x){
            temp=temp->next;
        }
        if(!temp->next){
            if(tail->value==x){
                insertatend(n);
            }
        }
        else{
            newnode->next=temp->next;
            newnode->prev=temp;
            newnode->next->prev=newnode;
            temp->next=newnode;

        }
    }
    void deletenode(int x){
        if(head==tail && head==nullptr){
            cout << "empty \n";
            return;
        }
        Node *temp=head;
        if(head->value==x){
            head->next->prev=nullptr;
            head=head->next;
            delete temp;
        }
        else{
            while(temp->next && temp->value!=x){
                temp=temp->next;
            }
            if(!temp->next){
                if(tail->value==x){
                    Node *yo=tail;
                    tail->prev->next=nullptr;
                    tail=tail->prev;
                    delete yo;
                }
            }
            else{
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                delete temp;
            }

        }
    }
    int search(int x) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return -1;
    }

    int count = 1;
    Node* temp1 = head;
    Node* temp2 = tail;
    bool found = false;

    while (temp1 != temp2 && temp1->next != temp2) {
        if (temp1->value == x) {
            cout << "It is found at " << count << " position \n";
            found = true;
            break;
        }
        else if (temp2->value == x) {
            cout << "It is found at " << -count << " position \n";
            found = true;
            break;
        }
        temp1 = temp1->next;
        temp2 = temp2->prev;
        count++;
    }

    
    if (!found) {
        if (temp1->value == x) {
            cout << "It is found at " << count << " position \n";
            found = true;
        }
        else if (temp2->value == x) {
            cout << "It is found at " << -count << " position \n";
            found = true;
        }
    }

    if (!found)
        cout << "Not found\n";

    return found ? count : -1;
    }
    int size(){
    if(head==tail && head==nullptr){
        cout << "empty \n";
        return 0;
    }
    int count = 0;
    Node* temp1 = head;
    Node* temp2 = tail;

    while (temp1 != temp2 && temp1->next != temp2) {
        temp1 = temp1->next;
        temp2 = temp2->prev;
        count=count+2;
    }
    if(temp1==temp2){
        return ++count;
    }
    else{
        count+=2;
        return count;
    }
    }
    void display(){
        if(head==tail && head==nullptr){
            cout << "empty \n";
            return;
        }
        else{
            Node* temp=head;
            while(temp->next){
                cout << temp->value << " => ";
                temp=temp->next;
            }
            cout << tail->value << endl ;
        }
    }
    bool iscircular(){
        Node *slow=head;
        Node *fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
    void displayreverse(){
        if(head==tail && head==nullptr){
            cout << "empty \n";
            return;
        }
        else{
            Node* temp=tail;
            while(temp->prev && head->next){
                cout << temp->value << " => ";
                temp=temp->prev;
            }
            cout << head->value << endl ;
        }
    }
    bool palindrome(){
    if (head == nullptr) {
    cout << "List is empty.\n";
    return false;
    }
    Node* temp1 = head;
    Node* temp2 = tail;
    

    while (temp1 != temp2 && temp1->next != temp2) {
        if (temp1->value !=temp2->value) {
            return false;
        }
        
        temp1 = temp1->next;
        temp2 = temp2->prev;
    }

    return ((temp1->value!=temp2->value) ? false:true);
}
};
Q1-Menu Driven with both Circular and Double inculcated in 1 Menu Driven Program
int main(){
    while(true){
        int n;
        cout << "what linked list do you want to operate on \n1)Doubly\n2)Circular\nEnter your choice(1/2): ";
        cout << endl;
        cin >>n;
        if(n==1){
            DoublyLinkedList d1;
            while(true){
                int Double_choice;
                cout << "what operation do you want to carry out" <<endl;
                cout << "1)Insert"<<endl;
                cout << "2)Delete"<<endl;
                cout << "3)Search"<<endl;
                cout << "4)display"<<endl;
                cout << "5)display Reverse"<<endl;
                cout << "Enter Choice(1-5):  ";
                cin>>Double_choice;
                cout << endl;
                switch (Double_choice)
                {
                case 1:
                    int insert_type;
                    cout << "where do you want to insert" << endl;
                    cout << "1)In beginning" << endl;
                    cout << "2)At end" << endl;
                    cout << "3)After specefic" << endl;
                    cout << "Enter Choice(1-3): " << endl;
                    cin >> insert_type;
                    cout << endl;
                    switch (insert_type)
                    {
                    case 1:{
                        int num;
                        cout << "enter number to add:  ";
                        cin >> num;
                        cout << endl;
                        d1.insertatbegin(num);
                        break;}
                    case 2:{
                        int num;
                        cout << "enter number to add:  ";
                        cin >> num;
                        cout << endl;
                        d1.insertatend(num);
                        break;}
                    case 3:{
                        int num,thresh;
                        cout << "enter number to add and after what number:  ";
                        cin >> num>>thresh;
                        cout << endl;
                        d1.insertatspecefic(num,thresh);
                        break;}
                    
                    }
                    break;
                case 2:{
                    int num;
                    cout << "enter number to delete:  ";
                    cin >> num;
                    cout << endl;
                    d1.deletenode(num);
                    break;}
                case 3:{
                    int num;
                    cout << "enter number to find:  ";
                    cin >> num;
                    cout << endl;
                    d1.search(num);
                    break;}
                case 4:
                    d1.display();
                    break;
                case 5:
                    d1.displayreverse();
                    break;
                
                }
                int cont;
                cout << "do you want to continue(0/1): "<< endl;
                cin>>cont;
                if(!cont){
                    break;
                }
            }
        }
        else if(n==2){
            CircularLinkedList d1;
            while(true){
                int Double_choice;
                cout << "what operation do you want to carry out" <<endl;
                cout << "1)Insert"<<endl;
                cout << "2)Delete"<<endl;
                cout << "3)Search"<<endl;
                cout << "4)display"<<endl;
                cout << "5)display Reverse"<<endl;
                cout << "Enter Choice(1-5):  ";
                cin>>Double_choice;
                cout << endl;
                switch (Double_choice)
                {
                case 1:
                    int insert_type;
                    cout << "where do you want to insert" << endl;
                    cout << "1)In beginning" << endl;
                    cout << "2)At end" << endl;
                    cout << "3)After specefic" << endl;
                    cout << "Enter Choice(1-3): " << endl;
                    cin >> insert_type;
                    cout << endl;
                    switch (insert_type)
                    {
                    case 1:{
                        int num;
                        cout << "enter number to add:  ";
                        cin >> num;
                        cout << endl;
                        d1.insertatbegin(num);
                        break;}
                    case 2:{
                        int num;
                        cout << "enter number to add:  ";
                        cin >> num;
                        cout << endl;
                        d1.insertatend(num);
                        break;}
                    case 3:{
                        int num,thresh;
                        cout << "enter number to add and after what number:  ";
                        cin >> num>>thresh;
                        cout << endl;
                        d1.insertatspecefic(num,thresh);
                        break;}
                    
                    }
                    break;
                case 2:{
                    int num;
                    cout << "enter number to delete:  ";
                    cin >> num;
                    cout << endl;
                    d1.deletenode(num);
                    break;}
                case 3:{
                    int num;
                    cout << "enter number to find:  ";
                    cin >> num;
                    cout << endl;
                    d1.search(num);
                    break;}
                case 4:
                    d1.display();
                    break;
                case 5:
                    d1.displayreverse();
                    break;
                
                }
                int cont;
                cout << "do you want to continue(0/1): "<< endl;
                cin>>cont;
                if(!cont){
                    break;
                }
            }
        }
        int choice;
        cout << "do you want to continue\n1)continue\n2)end\nEnter your choice(1/2):  ";
        cin>> choice;
        cout << endl;
        if(choice-1){
            break;
        }
        
    }
}
Q2
int main(){
    CircularLinkedList c1;
    c1.insertatbegin(50);
    c1.insertatbegin(40);
    c1.insertatbegin(30);
    c1.insertatbegin(20);
    c1.insertatbegin(10);
    c1.display_head();
}
Q3
int main(){
    CircularLinkedList c1;
    c1.insertatbegin(50);
    c1.insertatbegin(40);
    c1.insertatbegin(30);
    c1.insertatbegin(30);
    c1.insertatbegin(20);
    c1.insertatbegin(10);
    c1.display();
    cout << c1.size()<<endl;

    DoublyLinkedList d1;
    d1.insertatbegin(50);
    d1.insertatbegin(40);
    d1.insertatbegin(30);
    d1.insertatbegin(20);
    d1.insertatbegin(10);
    d1.display();
    cout << d1.size()<<endl;

}
Q4
int main(){
    DoublyLinkedList d1;
    d1.insertatbegin(1);
    d1.insertatbegin(1);
    d1.insertatbegin(1);
    d1.insertatbegin(0);
    d1.insertatbegin(1);
    if(d1.palindrome()){
        cout << "palindrome"<<endl;
    }
    else{
        cout << "no palindrome"<<endl;
    }
}
Q5
int main(){
    CircularLinkedList c1;
    c1.insertatbegin(50);
    c1.insertatbegin(40);
    c1.insertatbegin(30);
    c1.insertatbegin(30);
    c1.insertatbegin(20);
    c1.insertatbegin(10);
    if(c1.iscircular()){
        cout << "circular"<<endl;
    }
    else{
        cout << "no circular"<<endl;
    }

    DoublyLinkedList d1;
    d1.insertatbegin(50);
    d1.insertatbegin(40);
    d1.insertatbegin(30);
    d1.insertatbegin(20);
    d1.insertatbegin(10);
    if(d1.iscircular()){
        cout << "circular"<<endl;
    }
    else{
        cout << "no circular"<<endl;
    }
    
}

