#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int src;
    int dest;
};

class Graph{
    int V;
    int E;
    public:
    Edge *edge;
    Graph(int v, int e){
        V =v;
        E= e;
        edge = new Edge[e];
    }
    
    int find_parents(int parent[], int i){
        if(parent[i] == -1)
            return i;
        return find_parents(parent,parent[i]);
    }
    
    void make_union(int parent[], int x, int y){
        int x_set = find_parents(parent,x);
        int y_set = find_parents(parent,y); 
        parent[x_set] = y_set;
   }

    bool iscyclic(){
        int *parent = new int[V];
        for(int i=0;i<V;i++){
            parent[i] = -1;
        }

        for(int i = 0;i<E;i++){
            int x = find_parents(parent,edge[i].src);
            int y = find_parents(parent,edge[i].dest);

            if(x==y){
                return 1;
            }
          make_union(parent,x,y);
        }
        return 0;
    }
};
int main() {
    int vertices;
    int Edges;

    cin>>vertices>>Edges;

    Graph g(vertices,Edges);
    for(int i  = 0;i<Edges;i++){
        int s,d;
        cin>>s>>d;
        (g.edge[i]).src = s;
        (g.edge[i]).dest = d;
    }

    if(g.iscyclic()){
        cout<<"YES"<<endl;
    }
    else
        cout<<"NO"<<endl;
}
