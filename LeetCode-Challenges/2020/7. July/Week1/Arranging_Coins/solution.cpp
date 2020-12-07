/*
    Complexity Analysis:

    Time - O(logn)
    Space - O(1)
*/

class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1;
        int count = 0;
        int value = n;
          
        while(value >= 0) {
            value -= i;
            i++;
            count++;
        }
        
        return count - 1;
    }
};