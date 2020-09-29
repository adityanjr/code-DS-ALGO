/*

Surrounded Regions
------------------

Solution
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

*/

class Solution {
public:
    void floodFill(vector<vector<char> >& board, int x, int y, char prevV, char newV) 
    { 
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size())     return; 
        if (board[x][y] != prevV)     return; 
        board[x][y] = newV; 

        floodFill(board, x+1, y, prevV, newV); 
        floodFill(board, x-1, y, prevV, newV); 
        floodFill(board, x, y+1, prevV, newV); 
        floodFill(board, x, y-1, prevV, newV); 
    } 
  
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0)  return;
        int n = board[0].size();
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == 'O')     board[i][j] = '-';  
            }
        } 
        for (int i=0; i<m; i++) {
            if (board[i][0] == '-')  floodFill(board, i, 0, '-', 'O');  
        }
        for (int i=0; i<m; i++) {
            if (board[i][n-1] == '-')  floodFill(board, i, n-1, '-', 'O');  
        }
        for (int i=0; i<n; i++) {
            if (board[0][i] == '-')  floodFill(board, 0, i, '-', 'O');  
        }
        for (int i=0; i<n; i++) {
            if (board[m-1][i] == '-')  floodFill(board, m-1, i, '-', 'O');  
        }
          
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == '-') board[i][j] = 'X';    
            } 
       }
          
     }
};