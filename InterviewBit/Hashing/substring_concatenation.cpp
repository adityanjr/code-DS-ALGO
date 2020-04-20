//  https://www.interviewbit.com/problems/substring-concatenation/

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    
    int x = B[0].size();
    int n = B.size();
    int m = A.size();
    
    unordered_map<string, int> mp;
    unordered_map<string, int> copy;
    
    for(auto b: B) {
        if(mp.find(b)==mp.end())
            mp.insert(pair<string, int> (b, 1));
        else
            mp[b]++;
            
        if(copy.find(b)==copy.end())
            copy.insert(pair<string, int> (b, 1));
        else
            copy[b]++;
    }
    
    vector<int> result;
    
    int i = 0;
    while(i<m-(n*x)+1) {
        
        string st = A.substr(i, n*x);
        
        for(int j=0;j<n*x-x+1;j+=x) {
            string s = st.substr(j, x);
           
            if(mp.find(s)!=mp.end()) {
                if(mp[s]>0) {
                    mp[s]--;
                }
                else
                    break;
            }
            else
                break;
        }
        
        unordered_map<string, int> :: iterator it;
        
        int count = 0;
        for(it=mp.begin();it!=mp.end();it++)
            if(it->second!=0) {
                count++;
                break;
            }
        
        if(count==0)
            result.push_back(i);
            
        mp.clear();
        mp.insert(copy.begin(), copy.end());
        i++;
    }
    return result;
}

