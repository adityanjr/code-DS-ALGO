/* You have to complete this function
which prints out the depth first level traversal of the 
graph starting from node s
the vector<int> g[i] represent the adjacency 
list of the ith node of the graph
 */
void dfs(int s, vector<int> g[], bool vis[])
{
    stack<int> st;
    
    bool done = false;
    
    while(!done){
        if(!vis[s]){
            vis[s] = true;
            cout << s << " ";
            
            for(int i = g[s].size()-1; i >= 0 ; i--){
                if(!vis[g[s][i]]){
                    st.push(g[s][i]);
                }
            }
        }
        
        if(st.empty()){
            done = true;
        }
        else{
            s = st.top();
            st.pop();
        }
    }
}
