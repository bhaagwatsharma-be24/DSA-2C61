#include <iostream> 
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int v){
        data = v;
        next = NULL;
    }
};

class CLL{
    Node* tail;
    public:
        CLL(){
            tail = NULL;}
        void insert (int v){
            Node *n = new Node(v);
            if(!tail){
                tail = n;
                tail->next = tail;
                return;
            }
            n->next = tail->next;
            tail->next = n;
            tail = n;
        }
        void display (){
            if(!tail) return;
            Node* head = tail->next;
            Node* t = head;
            do{
                cout<<t->data<<" ";
                t=t->next;
            }while(t!= head);
            cout<<head->data<<"\n";
        }
};

int main(){
    CLL c;
    c.insert(10);
    c.insert(20);
    c.insert(30);
    c.display();
}