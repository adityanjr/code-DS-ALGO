int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    vector<int> L(n);
    vector<int> R(n);
    
    int i, j;
    L[0] = A[0];
    for(i=1;i<n;i++)
        L[i] = min(L[i-1], A[i]);
    
    R[n-1] = A[n-1];
    for(i=n-2;i>=0;i--)
        R[i] = max(R[i+1], A[i]);
        
    int diff;
    i = j = diff = 0;
    
    while(i<n && j<n) {
        if(L[i]<=R[j]) {
            diff = max(diff, j-i);
            j++;
        }
        else
            i++;
    }
    return diff;
}

