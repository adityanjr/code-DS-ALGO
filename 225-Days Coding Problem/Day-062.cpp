/*
 *   
 *
This problem was asked by Facebook.

There is an N by M matrix of zeroes. Given N and M, write a function to count the number of ways of starting at the top-left corner and getting to the bottom-right corner. You can only move right or down.

For example, given a 2 by 2 matrix, you should return 2, since there are two ways to get to the bottom-right:

Right, then down
Down, then right
Given a 5 by 5 matrix, there are 70 ways to get to the bottom-right.

Similar LeetCode Problem : 62 Unique Paths

 *
 *
 *
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>grid(m , vector<int>(n,0));
        grid[0][0] = 1;
        for(int i=0;i<m;++i){
            for(int j = 0;j<n;++j){
                if(i+1<m){
                    grid[i+1][j]+=grid[i][j];
                }
                if(j+1<n){
                    grid[i][j+1]+=grid[i][j];
                }
            }
        }
        return grid[m-1][n-1];
    }
};
