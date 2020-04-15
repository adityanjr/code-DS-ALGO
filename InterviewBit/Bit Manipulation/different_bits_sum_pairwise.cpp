// https://www.interviewbit.com/problems/different-bits-sum-pairwise/

int Solution::cntBits(vector<int> &A) {
    int n = A.size();
long long bits[35] = {0};
    int mod = pow(10,9)+7;
    for (int i=0;i<35;i++) {
        int cnt = 0;
        for (int j=0;j<n;j++) {
            if (A[j]&(1LL <<i))
                cnt++;
        }
        bits[i] = cnt;
    }
    long long ans = 0;
    for (int i=0;i<35 ;i++)
        ans = (ans + 2*bits[i]*(n-bits[i]))%mod;
    return ans;
}


