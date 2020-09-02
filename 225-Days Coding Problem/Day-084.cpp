class Solution {
    int row,col;
    vector<vector<bool>>visited;
    void dfs(int i,int j, vector<vector<char>>&grid){
        if(i<0 || i>=row || j<0 || j>=col || visited[i][j] || grid[i][j]!='1'){
            return;
        }
        visited[i][j] = true;
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        row = (int)grid.size();
        if(!row)
            return 0;
        col = (int)grid[0].size();
        visited.assign(row,vector<bool>(col,false));
        int counter{};
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(grid[i][j]=='1' &&!visited[i][j]){
                    dfs(i,j,grid);
                    ++counter;
                }
            }
        }
        return counter;
    }
};

