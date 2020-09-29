/*

Longest Duplicate Substring
---------------------------

Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)

Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)

Example 1:

Input: "banana"
Output: "ana"
Example 2:

Input: "abcd"
Output: ""
 

Note:

2 <= S.length <= 10^5
S consists of lowercase English letters.

*/

class Solution {
public:
    string longestDupSubstring(string S) {
        std::string_view longest;
        std::unordered_set<std::string_view> set;
        int start = 1;
        int end = S.size() - 1;
        while (start <= end)
        {
            int len = start + (end - start) / 2;
            bool found = false;
            for (int i = 0; i != S.size() - len + 1; ++i)
            {
                const auto [it, inserted] = set.emplace(S.data() + i, len);
                if (!inserted)
                {
                    found = true;
                    longest = *it;
                    break;   
                }
            }
            
            if (found)
                start = len + 1;
            else
                end = len - 1;
            
            set.clear();      
        }
            
        return {longest.begin(), longest.end()};
    }
};