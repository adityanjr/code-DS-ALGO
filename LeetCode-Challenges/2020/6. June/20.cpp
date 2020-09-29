/*

Permutation Sequence
--------------------

The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"

*/

class Solution {
public:
    string getPermutation(int n, int k) {
          string ans = "";
          vector <char> candidates(n);
          for(long long i = 0; i < n; i++)
             candidates[i] = ((i + 1) + '0');
          vector <long long> fact(n + 1);
          fact[0] = 1;
          for(long long i = 1; i <= n; i++)
             fact[i] = fact[i - 1] * i;
          k--;
          for(long long i = n - 1; i >= 0; i--){
             long long idx = k / fact[i];
             ans += candidates[idx];
             for(long long j = idx; j + 1< candidates.size(); j++)
                candidates[j] = candidates[j + 1];
             k = k % fact[i];
          }
          return ans;
    }
};