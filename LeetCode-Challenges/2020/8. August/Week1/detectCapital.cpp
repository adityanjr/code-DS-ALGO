class Solution {
public:
    bool detectCapitalUse(string word) {
        int numOfCapitals = 0;
        
        for(char ch: word) {
            if(isupper(ch)) numOfCapitals++;
        }
        
        return numOfCapitals == word.size() || numOfCapitals == 0 || (numOfCapitals == 1 && isupper(word[0]));
    }
};