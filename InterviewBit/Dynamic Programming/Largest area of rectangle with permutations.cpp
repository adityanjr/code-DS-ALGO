//  https://www.interviewbit.com/problems/largest-area-of-rectangle-with-permutations/

int Solution::solve(vector<vector<int> > &A) {
    
    int n = A.size();
    int m = A[0].size();
    
    int aux[n][m];
    int area, ans = 0;
    
    for(int j=0;j<m;++j)
        aux[0][j] = A[0][j];
    
    for(int j=0;j<m;++j)
        for(int i=1;i<n;++i)
            aux[i][j] = (A[i][j]==0)?0:1+aux[i-1][j];
    
    for(int i=0;i<n;++i) {
        vector<int> sa(n+1, 0);
        
        for(int j=0;j<m;++j)
            sa[aux[i][j]]++;
        
        int k = n;
        int t = 0;
        while(k>=0) {
            while(sa[k]>0) {
                aux[i][t] = k;
                sa[k]--;
                t++;
            }
            k--;
        }
        
        for(int j=0;j<m;++j)
            ans = max(ans, aux[i][j]*(j+1));
    }
    return ans;
}

