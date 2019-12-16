#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    map<T,list<T>>adj;
    int V;
    public:
    Graph(int a){
        V= a;
    }
    void addEdge(T u, T v, bool bidir = true){
              adj[u].push_back(v);
              if(bidir){
                  adj[v].push_back(u);
              }
        }

    void dfshelper(T node, map<T,bool>&visited){
        visited[node] =  true;
        for( auto neighbour: adj[node]){
            if(!visited[neighbour])
              dfshelper(neighbour,visited);
        }
    }
    int dfs(T src){
        map<T,bool>visited;
        dfshelper(src,visited);
        return visited.size();
    }

    bool strictlyconnectedcomponents(){
        map<T,list<T>>adj1;
        
        int size1 =  dfs(1);
        //cout<<size1;
        for(auto i: adj){
            T node = i.first;
            for(auto j: adj[node]){
                adj1[j].push_back(node);
            }
        }
        adj =  adj1;
        int size2 = dfs(1);
        //cout<<size2;
        if(size1 == size2 && size1 ==V){
            return true;
        }
        else
            return false;

    }
};
int main() {
    
    Graph<int>g(3);
    g.addEdge(1,2,false);
    g.addEdge(1,3,false);
    g.addEdge(3,2,false);
    cout<<g.strictlyconnectedcomponents();
}