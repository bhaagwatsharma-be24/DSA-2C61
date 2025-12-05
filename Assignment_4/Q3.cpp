#include<bits/stdc++.h>
using namespace std;

void interleave(queue<int> &q){
    int n= q.size();
    if(n%2!=0){
        cout<<"Not possible"<<endl;
    }

    int mid = n/2;
    queue<int> q0;

    for(int i =0;i<mid;i++){
        q0.push(q.front());
        q.pop();
    }

    while(!q0.empty()){
        q.push(q0.front());
        q0.pop();

        q.push(q.front());
        q.pop();
    }
}

void display(queue<int> q){
    while(!q.empty()) {
    cout<<q.front()<<" ";
    q.pop();
    }
}

int main(){
    queue<int> q;
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);

    display(q);
    cout<<endl;
    cout<<"After interleave : "<<endl;
    interleave(q);
    display(q);

    return 0;
}