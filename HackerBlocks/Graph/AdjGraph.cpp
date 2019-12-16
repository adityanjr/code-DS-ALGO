#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
      map<T,list<T>>adj;
      public:
      void addEdge(T u, T v, bool bidir = true){
          adj[u].push_back(v);
          if(bidir == true){
              adj[v].push_back(u);
          }
      }

      void printGraph(){
          for(auto i: adj){
              cout<<i.first<<"->";

              for(auto j:i.second){
                  cout<<j<<",";
              }
              cout<<endl;
          }
      }
};


/* For integer Data type 
class Graph{
    int V;
    list<int> *adj;
    public:
        Graph(int v){
            V = v;
            adj =  new list<int>[V];
        }
    
    void addEdge(int,int, bool);
    void printGraph();
};

void Graph::addEdge(int u, int v, bool bidir=true){
     adj[u].push_back(v);
     if(bidir == true){
         adj[v].push_back(u);
     }
}

void Graph::printGraph(){

    for(int i=0;i<V;i++){
        cout<<i<<"->";
        for(auto val : adj[i]){
            cout<<val<<",";
        }
        cout<<endl;
    }
}

*/ 


int main() {
    Graph<string>g;
    g.addEdge("Putin","Trump",false);
    g.addEdge("Putin","Modi",false);
    g.addEdge("Putin","Pope",false);
    g.addEdge("Modi","Trump",true);
    g.addEdge("Modi","Yogi",true);
    g.printGraph();
}
