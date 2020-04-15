//  https://www.interviewbit.com/problems/min-xor-value/

int Solution::findMinXor(vector<int> &A) {
    int n = A.size();
    if(n==0)
        return A[0];
    sort(A.begin(), A.end());
    int d = A[0]^A[1];

    for(int i=1;i<n;i++) {
        
        int x = A[i-1]^A[i];
        d = min(d, x);
       
    }
    return d;
}

