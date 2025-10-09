#include<iostream>
using namespace std;

class queue{
    int arr[100];
    int head;
    int tail;
    public:
    queue(){
        head=tail=-1;
    }
    void enqueue(int n){
        if (isempty()){
            head=tail=0;
            arr[head]=n;
        }
        else if(isfull()){
            cout << "q full"<<endl;
        }
        else{
            tail+=1;
            arr[tail]=n;
        }
    }
    bool isempty(){
        if((head==-1 && tail==head)|| head>tail){
            return true;
        }
        else{
            return false;
        }
    }
    bool isfull(){
        if(tail==99){
            return true;
        }
        else{
            return false;
        }
    }
    int dequeue(){
        if(isempty()){
            cout <<"q empty"<<endl;
            return -1;
        }
        int a=arr[head++];
        return a;
    }
    int peek(){
        return arr[head];
    }
    void display(){
        if(isempty()){
            cout <<"empty"<<endl;
        }
        else{
            for(int i=head;i<=tail;i++){
                cout << arr[i]<<" ";
            }
            cout <<endl;
        }
    }
    int size(){ 
        if(isempty()) return 0; 
        return tail - head + 1; 
    }


};
q1
int main(){
    queue q1;
    while (true){
        int n;
        cout << "what queue operation would you like to execute"<<endl;
        cout << "1: Enqueue"<<endl;
        cout << "2: Dequeue"<<endl;
        cout << "3: isEmpty()"<<endl;
        cout << "4: isFull()"<<endl;
        cout << "5: peek()"<<endl;
        cout << "6: display"<<endl;
        cin>>n;
        cout <<endl;
        if(n==1){
            int num;
            cout<<"enter number:  "<<endl;
            cin>>num;
            cout <<endl;
            q1.enqueue(num);
        }
        else if(n==2){
            int n=q1.dequeue();
            cout << n<<"has been removed"<<endl;
        }
        else if(n==3){
            if(q1.isempty()){
                cout <<"queue is empty"<<endl;
            }
        }
        else if(n==4){
            if(q1.isfull()){
                cout <<"queue is full "<<endl;
            }
        }
        else if(n==5){
            int num=q1.peek();
            cout << num<< "is at first place"<<endl;
        }
        else if(n==6){
            q1.display();
        }
        cout <<endl;
        cout << "do you want to continue(1/0) ";
        cin>>n;
        cout <<endl;
        if(!n){
            break;
        }
    }
}
#include <iostream>
using namespace std;

class circularqueue {
    int arr[10];
    int head;
    int tail;
    int size;
public:
    circularqueue() {
        head = tail = -1;
        size = 10;
    }

    bool isEmpty() {
        return (head == -1);
    }

    bool isFull() {
        return ((tail + 1) % size == head);
    }

    void Enqueue(int n) {
        if (isFull()) {
            cout << "Queue full" << endl;
            return;
        }
        if (isEmpty()) {
            head = tail = 0;
        } else {
            tail = (tail + 1) % size;
        }
        arr[tail] = n;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue empty" << endl;
            return -1;
        }
        int val = arr[head];
        if (head == tail) {
            head = tail = -1;
        } else {
            head = (head + 1) % size;
        }
        return val;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue empty" << endl;
            return -1;
        }
        return arr[head];
    }

    void display() {
        if (isEmpty()) {
            cout << "empty" << endl;
            return;
        }
        int i = head;
        while (true) {
            cout << arr[i] << " ";
            if (i == tail) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};
q2
int main() {
    circularqueue cq1;
    if (cq1.isEmpty()) cout << "yo yo" << endl;

    cq1.Enqueue(5);
    cq1.Enqueue(2);
    cq1.Enqueue(7);
    cq1.display();   

    cout << "Dequeued: " << cq1.dequeue() << endl; 
    cq1.display();   

    cq1.Enqueue(9);
    cq1.Enqueue(11);
    cq1.display();   

    cout << "Peek: " << cq1.peek() << endl;
}
q3
int main(){
    int arr[6]={1,2,3,4,5,6};
    int size=6;
    int half=size/2;
    
    queue q;
    queue firthalf;
    queue finalqueue;
    for(int i=0;i<size;i++){
        q.enqueue(arr[i]);
    }
    for(int i=0;i<half;i++){
        firthalf.enqueue(q.dequeue());
    }
    for(int i=0;i<half;i++){
        finalqueue.enqueue(firthalf.dequeue());
        finalqueue.enqueue(q.dequeue());
    }
    finalqueue.display();
}
q4
#include<string>
class queuestr {
    char arr[100];
    int head, tail;
public:
    queuestr() { head = tail = -1; }
    void enqueue(char c) {
        if (isfull()) { cout << "q full\n"; return; }
        if (isempty()) head = tail = 0;
        else tail++;
        arr[tail] = c;
    }
    char dequeue() {
        if (isempty()) return '\0';
        return arr[head++];
    }
    char peek() {
        if (isempty()) return '\0';
        return arr[head];
    }
    bool isempty() { return (head == -1 || head > tail); }
    bool isfull() { return (tail == 99); }
};

int main(){
    string s;
    cout <<"enter string: "<<endl;
    // cin.ignore();
    getline(cin,s);

    int freq[256]={0};
    queuestr q;

    for(int i=0;i<s.length();i++){
        if(s[i]==' '){continue;}
        freq[s[i]]++;
        q.enqueue(s[i]);
        while(!q.isempty() && freq[q.peek()]>1){
            q.dequeue();
        }
        if(q.isempty()){ cout << "-1"<<" ";}
        else{cout << q.peek()<< " ";}

    }
    cout << endl;
}
q5 a
class stackUsingQueues {
    queue q1, q2;
public:
    void push(int x){
        q2.enqueue(x);
        while(!q1.isempty()){
            q2.enqueue(q1.dequeue());
        }
        swap(q1, q2);
    }

    int pop(){
        if(q1.isempty()){
            cout << "Stack empty\n";
            return -1;
        }
        return q1.dequeue();
    }

    int top(){
        if(q1.isempty()){
            cout << "Stack empty\n";
            return -1;
        }
        return q1.peek();
    }

    bool isempty(){
        return q1.isempty();
    }
};

int main(){
    stackUsingQueues s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl;
    cout << "Pop: " << s.pop() << endl;
    cout << "Top: " << s.top() << endl;
    s.push(40);
    cout << "Top: " << s.top() << endl;

    while(!s.isempty()){
        cout << s.pop() << " ";
    }
    cout << endl;
}
class stackUsingOneQueue {
    queue q;
public:
    void push(int x){
        int n = q.size();
        q.enqueue(x);
        for(int i = 0; i < n; i++){
            q.enqueue(q.dequeue());
        }
    }

    int pop(){
        if(q.isempty()){
            cout << "Stack empty\n";
            return -1;
        }
        return q.dequeue();
    }

    int top(){
        if(q.isempty()){
            cout << "Stack empty\n";
            return -1;
        }
        return q.peek();
    }

    bool isempty(){
        return q.isempty();
    }
};

int main(){
    stackUsingOneQueue s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl;
    cout << "Pop: " << s.pop() << endl;
    cout << "Top: " << s.top() << endl;
    s.push(40);
    cout << "Top: " << s.top() << endl;

    while(!s.isempty()){
        cout << s.pop() << " ";
    }
    cout << endl;
}
