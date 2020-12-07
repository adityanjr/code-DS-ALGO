class Solution {
    bool is_vowel(char c) {
        char lc = tolower(c);
        return lc == 'a' || lc == 'e' || lc == 'i' || lc == 'o' || lc == 'u';
    }
    
    vector<string> split(string S) {
        vector<string> result;
        string subs = "";
        
        for(char c: S) {
            if(c != ' ') subs += c;
            else {
                result.push_back(subs);
                subs = "";
            }
        }
        
        result.push_back(subs);
        
        return result;
    }
    
public:
    string toGoatLatin(string S) {
        vector<string> words = split(S);
        string result = "";
        string suff = "";
        
        for(int i = 0; i < words.size(); ++i) {
            string word = words[i];
            suff.push_back('a');
            
            if(!is_vowel(word[0])) result += word.substr(1) + word[0];
            else result += word;
            
            result += "ma" + suff + " ";
        }
        
        result.pop_back();
        
        return result;
    }
};