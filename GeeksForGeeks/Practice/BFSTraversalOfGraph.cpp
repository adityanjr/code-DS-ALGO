/* You have to complete this function*/
void bfs(int s,vector<int> adj[],bool vis[])
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    
    while(!q.empty()){
        int curr = q.front();
        for(int i = 0; i < adj[curr].size(); i++){
            if(!vis[adj[curr][i]]){
                q.push(adj[curr][i]);
                vis[adj[curr][i]] = true;
            }
        }
        cout << curr << " ";
        q.pop();
    }
}
