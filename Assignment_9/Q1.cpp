
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

    //BFS
    void bfs(){
        queue<int> Q;
        vector<bool> vis(V,false);

        Q.push(0);
        vis[0] = true;
        while(Q.size()>0){
            int u = Q.front();
            Q.pop();

            cout<< u << " ";

            for(int v:l[u]){
                if(!vis[v]){
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }
        cout<<endl;
    }
};

int main(){
    graph g(5);
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(1,3);
    g.addedge(2,3);
    g.addedge(2,4);

    g.bfs();
    return 0;
}