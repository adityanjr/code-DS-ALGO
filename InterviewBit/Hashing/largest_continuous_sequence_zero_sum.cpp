//  https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/

vector<int> Solution::lszero(vector<int> &A) {
    
    int ans = 0;
    int n = A.size();
    unordered_map<int, pair<int, int> > mp;
    
    vector<int> sum;
    
    for(int i=0;i<n;i++) {
        ans += A[i];
        
        if(mp.find(ans)==mp.end())
            mp[ans] = make_pair(i, -1);
        else
            mp[ans] = make_pair(mp[ans].first, i);
            
    }
    
    int start, final;
    start = A.size();
    final = 0;
    
    for(auto it=mp.begin();it!=mp.end();it++) {
        if(it->first==0) {
            if(it->second.second==-1)
                final = it->second.first;
            else
                final = it->second.second;
            start = -1;
        }
        else if(it->second.second!=-1) {
            if((final-start)<(it->second.second-it->second.first)) {
                start = it->second.first;
                final = it->second.second;
            }
            if((final-start)==(it->second.second-it->second.first) && (start>it->second.first)) {
                start = it->second.first;
                final = it->second.second;
            }
        }
    }
    
    vector<int> result;
    
    for(int i=start+1;i<final+1;i++)
        result.push_back(A[i]);
    return result;
}

