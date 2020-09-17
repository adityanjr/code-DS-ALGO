class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> anag;
        vector<vector<string>> result;
        for (string str : strs)
        {
            string s = str;
            sort(s.begin(), s.end());
            anag[s].emplace_back(str);
        }
        for (auto s : anag)
        {
            result.emplace_back(s.second);
        }
        return result;
    }
};