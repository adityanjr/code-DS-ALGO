class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        bool saw_single_char = false;
        int total = 0;
        
        for(char ch: s) m[ch]++;
        
        for(auto &x: m) {
            if(x.second % 2 == 0) total += x.second;
            else {
                total += x.second - 1;
                saw_single_char = true;
            }
        }
        
        return saw_single_char ? total + 1 : total;
    }
};