#include <bits/stdc++.h>
using namespace std;
#define inf 1e9

class Graph{

    int V;
    int E;
    list<pair<int,int>> *adj;
    public:
    Graph(int v,int e){
        V=v;
        E=e;
        adj = new list<pair<int,int>>[v];
    }

    void addEdge(int a, int b, int w){
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    int findminvertex(int *weight, bool *visited, int v){
        int minVertex  = -1;
        for(int i = 0;i<V;i++){
            if(!visited[i] &&(minVertex==-1 || weight[i]<weight[minVertex])){
                minVertex = i;
            }
        }
        return minVertex;
    }

    void prims(){
        bool *visited =  new bool[V];
        int *parent = new int[V];
        int *weight = new int[V];

        for(int i = 0;i<V;i++){
             visited[i] =  false;
             weight[i] = inf;
        }
        parent[0] =  -1;
        weight[0] = 0;

        for(int k= 0;k<V;k++){
            int minVertex = findminvertex(weight,visited,V);
            visited[minVertex] = true;
            for(auto neighbour: adj[minVertex]){
                if(!visited[neighbour.first]){
                    if(weight[neighbour.first]>neighbour.second){
                        parent[neighbour.first] = minVertex;
                        weight[neighbour.first] = neighbour.second;
                    }
                }
            }
        }
         for(int i=1;i<V;i++){
                cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
            }
     }
};


int main() {
    int V,E;
    cin>>V>>E;
    Graph g(V,E);
    for(int i = 0;i<E;i++){
        int s,d,w;
        cin>>s>>d>>w;
        g.addEdge(s,d,w);
    }
    g.prims();
}
