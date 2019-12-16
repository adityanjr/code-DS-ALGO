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

   bool isBipartite(T src){
        map<T,bool>visited;
        map<T,int>childcolor;
        queue<T>que;
        que.push(src);
        visited[src] = true;
        childcolor[src] = 0;
        int child = 1;
        while(!que.empty()){
            T node = que.front();
            que.pop();
            for(auto j: adj[node]){
                  if(!visited[j]){
                      que.push(j);
                      visited[j] = true;
                      childcolor[j] = child;
                  }
                  else if(visited[j] && childcolor[j]==childcolor[node]){
                      return false;
                  }
            }
            if(child) child = 0;
            else
                child = 1;
        }
        return true;
   }
};
int main() {

    Graph<int>g(3);
    g.addEdge(1,2,false);
    g.addEdge(2,3,false);
    g.addEdge(3,4,false);
    g.addEdge(4,1,false);
    cout<<g.isBipartite(1);
}
