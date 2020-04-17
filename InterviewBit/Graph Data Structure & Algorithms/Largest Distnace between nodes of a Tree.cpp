//  https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/

vector<int> dijkstra(int s, vector<int> adj[], int n) {
    
    vector<int> dist(n, -1);
    dist[s] = 0;
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    
    while(!q.empty()) {
        s = q.front();
        q.pop();
        
        for(int i=0;i<adj[s].size();i++) {
            int nd = 1 + dist[s];
            if(!visited[adj[s][i]]) {
                visited[adj[s][i]] = true;
                dist[adj[s][i]] = nd;
                q.push(adj[s][i]);
            }
        }
    }
    
    
    return dist;
}
int Solution::solve(vector<int> &A) {
    int n = A.size();
    if(n<2)
        return 0;
    else if(n==2)
        return 1;
    vector<int> adj[n];
    
    for(int i=1;i<n;i++) {
        adj[A[i]].push_back(i);
        adj[i].push_back(A[i]);
    }
    
    vector<int> dist(dijkstra(0, adj, n));
    
    int maxD = *max_element(dist.begin(), dist.end());
    int i = 0;
    for(;i<n;i++)
        if(dist[i]==maxD)
            break;
    dist.clear();
    //cout << maxD << " " << i << endl;
    dist = dijkstra(i, adj, n);
    return *max_element(dist.begin(), dist.end());
    
}

