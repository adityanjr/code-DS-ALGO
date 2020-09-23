class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> adj[N+1];
         vector<int> adj1[N+1];
        for(int i=0;i<trust.size();i++)
        {
            int x=trust[i][1];
            adj[x].push_back(trust[i][0]);
        }
        for(int i=0;i<trust.size();i++)
        {
            adj1[trust[i][0]].push_back(trust[i][1]);
        }
        for(int i=1;i<N+1;i++)
        {
            if(adj[i].size()==N-1)
            {
                if(adj1[i].size()==0)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};
