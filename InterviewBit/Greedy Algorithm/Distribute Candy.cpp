//  https://www.interviewbit.com/problems/distribute-candy/

int Solution::candy(vector<int> &A) {
    
    int n = A.size();
    int choc[n];
    fill_n(choc, n, 1);
    
    for(int i=1;i<n;i++) {
        if(A[i]>A[i-1])
            choc[i]= choc[i-1]+1;
    }
    
    for(int i=n-2;i>=0;i--) 
        if(A[i]>A[i+1] && choc[i]<=choc[i+1])
            choc[i] = 1+choc[i+1];
    
    int ans = 0;
    for(int i=0;i<n;i++)
        ans += choc[i];
    
    return ans;
}

