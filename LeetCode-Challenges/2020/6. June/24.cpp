/*

Unique Binary Search Trees
--------------------------

Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/

class Solution {
public:
    int rec(int n, map<int,int> &dp){
        if(n==0){
            dp[0] = 1;
            return 1;
        }
        if(dp.find(n)!=dp.end())
            return dp[n];
        int sum = 0;
        for(int k=1;k<=n;k++)
            sum += rec(n-k,dp)*rec(k-1,dp);
        dp[n] = sum;
        return sum;
    }
    int numTrees(int n) {
        map<int,int> dp;
        return rec(n,dp);
    }
};