/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
The structure of the class is as follows 
which contains an integer V denoting the no 
of vertices and a list of adjacency vertices.
class Graph
{
    int V;
    list<int> *adj;
public :
    Graph(int V);
    void addEdge(int v,int w);
    bool isCyclic();
};
*/

bool dfs(list<int>* adj, int V, int curr, map<int, bool>& visited, map<int, bool> visiting){
    if(visited.find(curr) != visited.end()){
        return false;
    }
    else if(visiting.find(curr) != visiting.end()){
        // cout << "visiting" << curr << endl;
        return true;
    }
    
    // cout << "normal" << curr << endl;
    visiting[curr] = true;
    
    list<int> l = adj[curr];
    list<int> :: iterator it = l.begin();
    
    while(it != l.end()){
        if(dfs(adj, V, *it, visited, visiting)){
            return true;
        }
        it++;
    }
    
    // cout << "visited" << curr << endl;
    visited[curr] = true;
    return false;
}

/*You are required to complete this method*/
bool Graph :: isCyclic()
{
    //Your code here
    map<int, bool> visited;
    
    for(int i = 0; i < V; i++){
        map<int, bool> visiting;
        if(dfs(adj, V, i, visited, visiting)){
            return true;
        }
    }
    
    return false;
}
