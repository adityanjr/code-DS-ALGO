//  https://www.interviewbit.com/problems/length-of-longest-subsequence/

int Solution::longestSubsequenceLength(const vector<int> &A) {
    
    int n = A.size();
    
    if(n<2)
        return n;
    
    vector<int> incr(n, 1);
    
    for(int i=1;i<n;i++) {
        int j = 0;
        while(j<i) {
            if(A[i]>A[j] && incr[i]<incr[j]+1)
                incr[i] = incr[j] + 1;
            j++;
        }
    }
    /*
    for(auto in: incr)
        cout << in << " ";
    cout << endl;
    */
    vector<int> decr(n, 1);
    
    for(int i=n-2;i>=0;i--) {
        int j = n-1;
        while(i<j) {
            if(A[i]>A[j] && decr[i]<decr[j]+1)
                decr[i] = decr[j] + 1;
            j--;
        }
    }
    /*
    for(auto dc: decr)
        cout << dc << " ";
    cout << endl;
    */
    int res = 0;
    for(int i=0;i<n;i++)
        res = max(res, incr[i]+decr[i]-1);
    
    return res;
}

