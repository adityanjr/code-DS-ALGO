#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int src;
    int dest;
    int weight;
};

class Set{
    public:
    int rank;
    int parent;
};

int find(Set *set, int i){
    if(set[i].parent!=i){
        set[i].parent = find(set,set[i].parent);
    }
    return set[i].parent;
}

void unions(Set *set, int x, int y){
    int x_root = find(set,x);
    int y_root = find(set,y);
    if(set[x_root].rank < set[y_root].rank){
        set[x_root].parent = y_root;
    }
    else if( set[x_root].rank > set[y_root].rank){
        set[y_root].parent = x_root;
    }
    else{
        set[y_root].parent = x_root;
        set[x_root].rank++;
    }
}

bool cmp(Edge e1, Edge e2){
    return e1.weight < e2.weight;
}

void kruskal(Edge edge[], int V, int E){
    sort(edge,edge+E,cmp);
    Edge *output  = new Edge[V-1];
    Set *set = new Set[V];
    for(int i = 0;i<V;i++){
        set[i].rank = 0;
        set[i].parent = i;
    }

    int counter = 0;
    for(int i = 0;i<E;i++){
        Edge temp = edge[i];
        int source = temp.src;
        int destination = temp.dest;
        int rootsource =  find(set,source);
        int rootdestination = find(set,destination);
        if(rootsource != rootdestination){
            output[counter] = temp;
            unions(set,source,destination);
            counter++;
        }
        if(counter==V-1)
            break;
    }
    cout<<"ans"<<endl;
    for(int i = 0;i<V-1;i++){
        cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
    }

}

int main() {
    int V,E;
    cin>>V>>E;
    Edge *edge = new Edge[E];
    for(int i = 0;i<E;i++){
        int s,d,w;
        cin>>s>>d>>w;
        edge[i].src = s;
        edge[i].dest = d;
        edge[i].weight = w;
    }
    kruskal(edge,V,E);
}
