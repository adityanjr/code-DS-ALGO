#define MOD 1e9+7

int Solution::cntInc(vector<int> &A) {
    int i=1, n = A.size();
    if(n<1)
        return 0;
    // if(allSame(A))
    //     return n;
    vector<vector<int> > ans;
    
    while(i<n) {
        vector<int> temp;
        if(A[i] > A[i-1]) {
            if(A[i-1])
            temp.push_back(i-1);
            while(i<n && A[i]>A[i-1]) {
                i++;
                temp.push_back(i-1);
            }
            
        } 
        if(temp.size())
            ans.push_back(temp);
        i++;
    }
    int res = 0;
    
    for(auto a: ans) {
        int temp = a.size()*(a.size()+1)/2-a.size();
        res = fmod((res + fmod(temp, MOD)),MOD);
    }
    res = fmod(res+n, MOD);
    return res;
}
