class Solution {
public:
    
    bool dfs(int num,vector <int> &visited,vector<int> graph[])
    {
        //cout<<num<<" ";
        if(visited[num]==1)
        {
            return false;
        }
        visited[num]=1;
        for(int i=0;i<graph[num].size();i++)
        {
            if(dfs(graph[num][i],visited,graph)==false)
            {
                return false;
            }
            
        }
        visited[num]=2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[numCourses];
        for(int i=0;i<prerequisites.size();i++)
        {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector <int> visited;
        for(int i=0;i<numCourses;i++)
        {
            visited.push_back(0);
        }
        int i=0;
        while(i<numCourses)
        {
            if(visited[i]==0  && !dfs(i,visited,graph))
            {
                return false;
            }
            i++;
        }
        return true;

        
    }
};