//  https://www.interviewbit.com/problems/tushars-birthday-party/


int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int max_cap = 0;
    for(auto a: A)
        max_cap = max(max_cap, a);
    int n = B.size();
    int m = max_cap;
    
    vector<vector<int> > T(n, vector<int> (m+1));
    
    for(int i=0;i<n;i++) {
        T[i][0] = 0;   
    }
    
    for(int i=0;i<n;i++) {
 
        for(int j=1;j<=m;j++) {
            if(i==0)
                T[i][j] = j*C[i];
            else if(j<B[i])
                T[i][j] = T[i-1][j];
            else {
                T[i][j] = min(T[i-1][j], T[i][j-B[i]]+C[i]);
            }
        }
    }
 
    int cost = 0;
    
    for(auto a: A)
        cost += T[n-1][a];
    return cost;
}
