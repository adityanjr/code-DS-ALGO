// DFS

class Solution {
    void dfs(vector<vector<int>>& graph, int source, int destination, vector<int> list, vector<vector<int>>& result) {
        list.push_back(source);
        if(source == destination) result.push_back(list);
        
        for(int vertex: graph[source]) {
            vector<int> currentList(list);
            dfs(graph, vertex, destination, currentList, result);
        }
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        dfs(graph, 0, graph.size() - 1, {}, result);
        return result;
    }
};

// BFS

class Solution {
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        int destination = graph.size() - 1;
        queue<vector<int>> q;
        
        q.push({0});
        
        while(!q.empty()) {
            vector<int> path = q.front();
            q.pop();
            
            int current = path[path.size() - 1];
            
            if(current == destination) result.push_back(path);
            
            for(int node: graph[current]) {
                vector<int> newPath(path);
                newPath.push_back(node);
                q.push(newPath);
            }
        }
        
        return result;
    }
};