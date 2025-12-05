#include<bits/stdc++.h>
#include<list>
#include<queue>
using namespace std;

class graph{
    int V;
    list<int> *l; //dynamic list of 
    
    public:
    graph(int V){
        this->V = V;
        //arr= new int[v]
        l = new list<int> [V];
    }

    void addedge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printadjlist(){
        for(int i=0;i<V;i++){
            cout<<i<<":";
            for(int neighbour : l[i]){
                cout<< neighbour << " ";
            }
            cout<<endl;
        }
    }

    //DFS
    void dfsHelper(int u,vector<bool> &vis){
        cout<<u<<" ";
        vis[u] = true;

        for(int v:l[u]){
            if(!vis[v]){
                dfsHelper(v,vis);
            }
        }
    }
    void dfs(){
        int src=0;
        vector<bool> vis(V,false);

        for(int i=0;i<V;i++){// for disconnected graphs 
            if(!vis[i]){
                dfsHelper(i,vis);
            }
        }
        dfsHelper(src,vis);
        cout<<endl;
    }
};

int main(){
    graph g(5);
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(1,3);
    g.addedge(2,4);


    cout<<"DFS: ";
    g.dfs();
    return 0;
}