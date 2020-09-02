/*
   
This problem was asked by Microsoft.

Given a 2D matrix of characters and a target word, write a function that returns whether the word can be found in the matrix by going left-to-right, or up-to-down.

For example, given the following matrix:

[['F', 'A', 'C', 'I'],
 ['O', 'B', 'Q', 'P'],
 ['A', 'N', 'O', 'B'],
 ['M', 'A', 'S', 'S']]

 and the target word 'FOAM', you should return true, since it's the leftmost column.
 Similarly, given the target word 'MASS', you should return true, since it's the last row.

 Similar LeetCode Problem : 79. Word Search

 */
class Solution {
    vector<vector<bool>>visited;
    vector<pair<int,int>>dir{{-1, 0}, {0, -1}, {0, 1},{1, 0}};
    int row , col;
    bool dfs(vector<vector<char>>&grid , string &word ,int r , int c , int index = 1){
        if(index == (int)word.size()){
            return true;
        }
        if(index > (int)word.size()){
            return false;
        }
        if(r>=row || c >=col){
            return false;
        }
        visited[r][c] = true;
        for(auto &itr: dir){
            if(r+itr.first <0 or r+itr.first>=row){
                continue;
            }
            if(c+itr.second <0 or c+itr.second>=col){
                continue;
            }
            if(grid[r+itr.first][c+itr.second]==word[index]){
                if(visited[r+itr.first][c+itr.second]==false && dfs(grid , word , r+itr.first, c+itr.second , index+1)){
                    return true;
                }
            }
        }
        visited[r][c] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        visited.resize(row , vector<bool>(col , false));
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(board[i][j] == word[0]){ // current character matches 
                    if(dfs(board , word ,i ,j , 1)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
