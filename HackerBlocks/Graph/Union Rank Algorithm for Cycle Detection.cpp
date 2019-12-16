#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int src;
    int dest;
};
class subset{
   public:
     int parent;
     int rank;
};

class Graph{
    int V;
    int E;
    public:
    Edge *edge;
    Graph(int v, int e){
        V = v;
        E = e;
        edge = new Edge[e];
    }
    
    int find(subset subsets[], int i){
        if(subsets[i].parent != i)
              subsets[i].parent =  find(subsets,subsets[i].parent);
        return  subsets[i].parent;
    }
    
    void Union(subset subsets[], int x, int y){
        int x_set = find(subsets,x);
        int y_set = find(subsets,y); 
        if(subsets[x_set].rank>subsets[y_set].rank){
            subsets[y_set].parent = x_set;
        }
        else if(subsets[x_set].rank<subsets[y_set].rank){
            subsets[x_set].parent  = y_set;
        }
        else{
            subsets[y_set].parent = x_set;
            subsets[x_set].rank++; 
        }
   }

    bool iscyclic(){
        subset *subsets = new subset[V];
        for(int i = 0;i<V;i++){
            subsets[i].rank = 0;
            subsets[i].parent = i;
        }

        for(int e = 0;e<E;e++){
            int x = find(subsets,edge[e].src);
            int y = find(subsets,edge[e].dest);

            if(x==y)
              return 1;
            
            Union(subsets,x,y);
        }
        return 0 ;
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
