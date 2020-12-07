/*
    Reference: @see https://www.geeksforgeeks.org/ugly-numbers/
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        int ugly[n];
        int index2 = 0, index3 = 0, index5 = 0;
        int next_multiple_of_2 = 2;
        int next_multiple_of_3 = 3;
        int next_multiple_of_5 = 5;
        int next_ugly_no = 1;
        ugly[0] = 1;
        
        for(int i = 1; i < n; ++i) {
            next_ugly_no = min(min(next_multiple_of_2, next_multiple_of_3), next_multiple_of_5);
            
            ugly[i] = next_ugly_no;
            
            if(next_ugly_no == next_multiple_of_2) {
                next_multiple_of_2 = ugly[++index2] * 2;
            }
            
            if(next_ugly_no == next_multiple_of_3) {
                next_multiple_of_3 = ugly[++index3] * 3;
            }
            
            if(next_ugly_no == next_multiple_of_5) {
                next_multiple_of_5 = ugly[++index5] * 5;
            }
        }
        
        return ugly[n - 1];
    }
};