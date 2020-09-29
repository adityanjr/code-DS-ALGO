/*

Largest Divisible Subset
------------------------

Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> v, next(n, -1), count(n, -1);
        int x = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] != 0) continue;
                if (next[i] == -1 || count[j] > count[next[i]]) next[i] = j;
            }
            count[i] = (next[i] == -1) ? 1 : count[next[i]]+1;
            if (x == -1 || count[i] > count[x]) x = i;
        }

        while (x != -1) { v.push_back(nums[x]); x = next[x]; }
        reverse(v.begin(), v.end());

        return v;
    }
};