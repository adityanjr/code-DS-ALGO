/*

Perfect Squares
---------------

Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

*/

class Solution {
public:
    bool isSquare(int n) {
        int sqroot = sqrt(n);
        return (n==(sqroot*sqroot));
    }
    int numSquares(int n) {
        while(n%4==0) n = n/4;
        if(n%8 == 7) return 4;
        if(isSquare(n)) return 1;
        for(int i=1;i*i<=n;i++) if(isSquare(n-i*i)) return 2;
        return 3;
    }
};