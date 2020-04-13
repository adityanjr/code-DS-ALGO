//  https://www.interviewbit.com/problems/letter-phone/

void generateComb(string A, int index, string &current, set<string> &result, unordered_map<int, string> mp) {
    int m = A.size();
    if(index==m) {
        if(current.size()==m)
            result.insert(current);
        return;
    }
    if(current.size()==m) {
        result.insert(current);
        return;
    }
    else if(current.size()>m)
        return;
    int key = A[index]-'0';
    
    int n = mp[key].size();
    
    for(int col=0;col<n;col++) {
        current += mp[key][col];
        generateComb(A, index+1, current, result, mp);
        current = current.substr(0, current.size()-1);
    }
    
}
vector<string> Solution::letterCombinations(string A) {
    
    string current="";
    set<string> result;
    
    unordered_map<int, string> mp;
    mp[0] = "0";
    mp[1] = "1";
    mp[2] = "abc";
    mp[3] = "def";
    mp[4] = "ghi";
    mp[5] = "jkl";
    mp[6] = "mno";
    mp[7] = "pqrs";
    mp[8] = "tuv";
    mp[9] = "wxyz";
    
    generateComb(A, 0, current, result, mp);
    
    vector<string> ans;
    for(auto s: result)
        ans.push_back(s);
    sort(ans.begin(), ans.end());
    return ans;
}

