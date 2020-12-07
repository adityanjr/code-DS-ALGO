/*
Single Number II
----------------

Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long long diff = 2147483648, len = 64;
        long long arr[64] = {0};
        for(int i=0; i<nums.size(); i++) {
            long long num = (nums[i] * 1LL + diff * 1LL);
            int j = 0;
            while(num) {
                arr[j] += (num%2) * 1LL;
                j++;
                num/=2;
            }
        }
        for(int i=0; i<len; i++) {
            arr[i] %= 3;
        }
        long long ans = diff * -1 * 1LL;
        for(int i=0; i<len; i++) {
            ans += (arr[i] == 1 ? (1<<i) : 0);
        }
        return ans;
    }
};
