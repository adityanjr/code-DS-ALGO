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

    bool checkforcycleBFS(T src){
        map<T,bool>visited;
        map<T,string>parent;
        queue<T>que;
        
        que.push(src);
        parent[src] = src;
        visited[src]  = true;
        while(!que.empty()){
            T node = que.front();
            que.pop();
            
            for(auto i:adj[node]){
                if(visited[i] && parent[node]!=i){
                    return true;
                }
                else{
                    visited[i] = true;
                    que.push(i);
                    parent[i] = node;
                }
            }
        }
        return false;
    }
};
int main() {
    
    Graph<string>g;
    g.addEdge("ENglish","Programming Logic",false);
    g.addEdge("Maths","Programming Logic",false);
    g.addEdge("Programming Logic","Python",false);
    g.addEdge("Programming Logic","HTML",false);
    g.addEdge("Programming Logic","Java",false);
    g.addEdge("Programming Logic","JS",false);
    g.addEdge("HTML","CSS",false);
    g.addEdge("CSS","JS",false);
    g.addEdge("JS","Web Dev",false);
    g.addEdge("Java","Web Dev",false);
    g.addEdge("Python","Web Dev",false);
    cout<<g.checkforcycleBFS("ENglish");
}
