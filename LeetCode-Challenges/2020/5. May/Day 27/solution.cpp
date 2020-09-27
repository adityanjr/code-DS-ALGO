class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
       
        vector<int> visited(N, -1); //If node is visited, then we will assign it a Group  
      vector<vector<int>> adj(N);
      for (int i=0; i< dislikes.size(); i++) {
        adj[(dislikes[i][0])-1].push_back((dislikes[i][1])-1);
        adj[(dislikes[i][1])-1].push_back((dislikes[i][0])-1);  
      }  
      for (int i=0; i<N; i++) {
        if (visited[i] == -1 && !DFS(i, visited, adj, 0))
          return false;  
      }
      return true;  
    }
    
    //Here group is group number that needs to be assigned to this node.
    bool DFS(int S, vector<int>& visited, vector<vector<int>>& adj, int group) {
      if (visited[S] == -1) visited[S] = group;
      else return (visited[S]==group); //If visited,check it is having req. group number.
        
      for (int i=0; i<adj[S].size(); i++) {
        if (!DFS(adj[S][i], visited, adj, 1-group)) //1-group will flip value of group
          return false;  
      }
      return true;  
        
    }
};