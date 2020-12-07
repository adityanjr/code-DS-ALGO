class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> inDegree(numCourses, 0);
        
        vector<int> result;
        
        for(vector<int> c: prerequisites) {
            inDegree[c[0]]++;
            graph[c[1]].push_back(c[0]);
        }
        
        queue<int> q;
        
        for(int i = 0; i < inDegree.size(); ++i) {
            if(inDegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            int current = q.front();
            q.pop();
            
            result.push_back(current);
            
            for(int node: graph[current]) {
                inDegree[node]--;
                if(inDegree[node] == 0) q.push(node);
            }
        }
        
        if(numCourses == result.size()) return result;
        
        return {};
    }
};