//  https://www.interviewbit.com/problems/word-break/

bool isAvail(string temp, vector<string> &B) {
    for(auto b: B)
        if(b==temp)
            return true;
    return false;
}
int Solution::wordBreak(string A, vector<string> &B) {
    int n = A.size();
    vector<bool> dp(n, false);
    vector<int> junc;
    junc.push_back(-1);
    
    for(int i=0;i<n;++i) {
        bool flag = false;
        
        for(int j=junc.size()-1;j>=0;--j) {
            string temp = A.substr(junc[j]+1, i-junc[j]);
            if(isAvail(temp, B)) {
                flag = true;
                break;
            }
        }
        
        if(flag) {
            junc.push_back(i);
            dp[i] = true;
        }
    }
    return dp[n-1];
}

