//  https://www.interviewbit.com/problems/distinct-numbers-in-window/

vector<int> Solution::dNums(vector<int> &A, int B) {
    
    unordered_map<int, int> mp;
    vector<int> res;
    
    int n = A.size();
    
    if(n<B || n==0)
        return res;
    
    for(int i=0;i<B;i++)
        mp[A[i]]++;
    
    res.push_back(mp.size());
    
    if(n==B) {
        return res;
    }
    
    int i = 0, j = B;
    while(j<n) {
        mp[A[j]]++;
        mp[A[i]]--;
        
        if(mp[A[i]]==0) {
            auto it = mp.find(A[i]);
            mp.erase(it);
        }
        
        res.push_back(mp.size());
        
        i++;
        j++;
    }
    return res;
}

