#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
    Node(int v){data=v;prev=next=NULL;}
};

class DLL {
    Node *head;
public:
    DLL(){head=NULL;}
    void insertFirst(int v){
        Node *n=new Node(v);
        n->next=head;
        if(head) head->prev=n;
        head=n;
    }
    void insertLast(int v){
        if(!head){insertFirst(v);return;}
        Node *t=head;
        while(t->next)t=t->next;
        Node *n=new Node(v);
        t->next=n;
        n->prev=t;
    }
    bool insertAfter(int k,int v){
        Node *t=head;
        while(t){
            if(t->data==k){
                Node *n=new Node(v);
                n->next=t->next;
                n->prev=t;
                if(t->next)t->next->prev=n;
                t->next=n;
                return 1;
            }
            t=t->next;
        }
        return 0;
    }
    bool insertBefore(int k,int v){
        Node *t=head;
        while(t){
            if(t->data==k){
                Node *n=new Node(v);
                n->next=t;
                n->prev=t->prev;
                if(t->prev)t->prev->next=n;
                else head=n;
                t->prev=n;
                return 1;
            }
            t=t->next;
        }
        return 0;
    }
    bool del(int k){
        Node *t=head;
        while(t){
            if(t->data==k){
                if(t->prev)t->prev->next=t->next;
                else head=t->next;
                if(t->next)t->next->prev=t->prev;
                delete t;
                return 1;
            }
            t=t->next;
        }
        return 0;
    }
    void display(){
        Node *t=head;
        while(t){
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<"\n";
    }
};

struct CNode{
    int data;
    CNode *next;
    CNode(int v){data=v;next=NULL;}
};

class CLL{
    CNode *tail;
public:
    CLL(){tail=NULL;}
    void insertFirst(int v){
        CNode *n=new CNode(v);
        if(!tail){tail=n;tail->next=tail;return;}
        n->next=tail->next;
        tail->next=n;
    }
    void insertLast(int v){
        insertFirst(v);
        tail=tail->next;
    }
    bool insertAfter(int k,int v){
        if(!tail)return 0;
        CNode *t=tail->next;
        do{
            if(t->data==k){
                CNode *n=new CNode(v);
                n->next=t->next;
                t->next=n;
                if(t==tail)tail=n;
                return 1;
            }
            t=t->next;
        }while(t!=tail->next);
        return 0;
    }
    bool del(int k){
        if(!tail)return 0;
        CNode *t=tail->next,*p=tail;
        do{
            if(t->data==k){
                if(t==p){delete t;tail=NULL;return 1;}
                p->next=t->next;
                if(t==tail)tail=p;
                delete t;
                return 1;
            }
            p=t;t=t->next;
        }while(t!=tail->next);
        return 0;
    }
    void display(){
        if(!tail){cout<<"\n";return;}
        CNode *t=tail->next;
        do{
            cout<<t->data<<" ";
            t=t->next;
        }while(t!=tail->next);
        cout<<"\n";
    }
};

int main(){
    DLL d;
    d.insertFirst(1);
    d.insertLast(2);
    d.insertAfter(1,3);
    d.display();
    d.del(2);
    d.display();

    CLL c;
    c.insertFirst(10);
    c.insertLast(20);
    c.insertAfter(10,15);
    c.display();
    c.del(20);
    c.display();
}