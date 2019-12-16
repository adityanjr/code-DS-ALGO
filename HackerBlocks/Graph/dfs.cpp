#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    map<T,list<T>>adj;
    public:
    void addEdge(T u, T v, bool bidir = true){
              adj[u].push_back(v);
              if(bidir){
                  adj[v].push_back(u);
              }
        }

    void dfshelper(T node, map<T,bool>visited){
        cout<<node<<endl;
        visited[node] =  true;
        for( auto neighbour: adj[node]){
            if(!visited[neighbour])
              dfshelper(neighbour,visited);
        }
    }
    void dfs(T src){
        map<T,bool>visited;
        dfshelper(src,visited);
    }
};
int main() {
    
    Graph<string>g;
    g.addEdge("Putin","Trump",false);
    g.addEdge("Putin","Modi",false);
    g.addEdge("Putin","Pope",false);
    g.addEdge("Modi","Trump",true);
    g.addEdge("Modi","Yogi",true);
    g.dfs("Putin");
}
