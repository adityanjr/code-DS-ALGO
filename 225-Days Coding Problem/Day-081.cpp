class Solution {
    vector<string> dialer = {
       "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    vector<string>result;
    void getString(string &digits, int index, string currentString) {
        if (index >= digits.size()) {
            result.push_back(currentString);
            return;
        }
        for (auto & itr: dialer[digits[index]-'0']) {
            getString(digits, index+1, currentString+itr);
        }
        return ;
    }
public:
    vector<string> letterCombinations(string digits) {
        result.clear();
        if (digits.size() != 0) {
            getString(digits, 0, "");
        }
        return result;
    }
};

