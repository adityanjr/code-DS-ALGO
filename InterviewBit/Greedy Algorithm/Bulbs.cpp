//  https://www.interviewbit.com/problems/bulbs/

int Solution::bulbs(vector<int> &A) {
    int ans = 0;
    int i = 0;
    int state = 0;
    
    for(;i<A.size();i++)
        if(A[i]==state) {
            ans++;
            state = 1-state;
        }
    return ans;
}

