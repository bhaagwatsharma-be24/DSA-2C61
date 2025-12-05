#include<bits/stdc++.h>
using namespace std; 
int main(){
    string str;
    cout<<"Enter the expression : ";
    cin>>str;

    unordered_map<char,int> freq;
    queue<char> q;
    for(char ch : str){
        freq[ch]++;
        q.push(ch);

        while(!q.empty() && freq[q.front()]>1){
            q.pop();
        }

        if(q.empty()) cout<< -1 <<" ";
        else cout<<q.front()<<" ";
    }
    return 0;
}