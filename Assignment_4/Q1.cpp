#include<bits/stdc++.h>
using namespace std;
#define SIZE 5

class Queue{
    int arr[SIZE];
    int r,f;

    public:

    Queue(){
        f = -1;
        r = -1;
    }

    bool isempty(){
        return (f==-1 && r==-1);
    }
    bool isfull(){
        return (r==SIZE-1);
    }
    void enqueue(int x){
        if(isfull()){
            cout<<"Queue is full\n";
            return;
        }
        if(isempty()){
            f = r = 0;
        }
        else{
            r++;
        }
        arr[r]=x;
    }
    void dequeue(){
        if(isempty()){
            cout<<"Queue is empty\n";
            return;
        }
        if(f==r){
            f = r =-1;
        }
        else{
            f++;
        }
    }
    void peek(){
        if(isempty()){
            cout<<"Queue is empty\n";
        }
        else{
            cout<<"Front is : "<<arr[f]<<endl;
        }
    }
    void display(){
        if(isempty()){
            cout<<"Queue is empty\n";
            return;
        }
        cout<<"Queue elements : ";
         for(int i=f;i<=r;i++) {
            cout<<arr[i]<< " ";
        }
        cout << endl;
    }

};

int main(){

    Queue q;
    int choice,val;

    while(choice!=0){
        cout<<"----Queue Menu----\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";  
        cin>>choice;
        switch (choice) {
        case 1:
        cout << "Enter value to enqueue: ";
        cin >> val;
        q.enqueue(val);
        break;
        case 2:
        q.dequeue();
        break;
        case 3:
        q.peek();
        break;
        case 4:
        q.display();
        break;
        case 5:
        cout << (q.isempty() ? "Queue is EMPTY\n" : "Queue is NOT empty\n");
        break;
        case 6:
        cout << (q.isfull() ? "Queue is FULL\n" : "Queue is NOT full\n");
        break;
        case 0:
        cout << "Exiting program...\n";
        break;
        default:
        cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}