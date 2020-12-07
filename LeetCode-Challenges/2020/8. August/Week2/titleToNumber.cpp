class Solution {
public:
    int titleToNumber(string s) {
        int power = 0;
        int n = s.size();
        int result = 0;
        
        for(int i = n - 1; i >= 0; --i) {
            result += (s[i] - 'A' + 1) * (int) pow(26, power++);
        }
        
        return result;
    }
};