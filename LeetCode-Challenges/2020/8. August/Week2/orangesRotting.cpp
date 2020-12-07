class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int freshOranges = 0;
        int time = 0;
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] == 2) q.push(make_pair(i, j));
                if(grid[i][j] == 1) freshOranges++;
            }
        }
        
        while(!q.empty() && freshOranges > 0) {
            time++;
            
            int size = q.size();
            
            while(size-- > 0) {
                pair<int, int> coords = q.front();
                q.pop();
                
                for(vector<int> d: directions) {
                    int x = coords.first + d[0];
                    int y = coords.second + d[1];
                    
                    if(x < 0 || x >= grid.size() || y < 0 || y >= grid[x].size() || grid[x][y] == 0 || grid[x][y] == 2) continue;
                    
                    grid[x][y] = 2;
                    freshOranges--;
                    
                    q.push(make_pair(x, y));
                }
            }
        }
        
        return freshOranges == 0 ? time : -1;
    }
};