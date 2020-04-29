//  https://www.interviewbit.com/problems/diffk/

int b_search(vector<int> &A, int d) {
    int l=0, r=A.size()-1;
    
    int res = -1;
    
    while(l<=r) {
        int m = l+(r-l)/2;
        if(A[m]==d) {
            res = m;
            break;
        }
        else if(A[m]>d) 
            r = m-1;
        else
            l = m+1;
    }
    return res;
}
int Solution::diffPossible(vector<int> &A, int B) {
    
    if(A.size()<2)
        return 0;
    
    for(int i=0;i<A.size();i++) {
        int d = A[i]-B;
        int res = b_search(A, d);
        if(res!=-1 && res!=i)
            return 1;
        
        int e = A[i]+B;
        res = b_search(A, e);
        if(res!=-1 && res!=i)
            return 1;
    }
    
    
    
    return 0;
}

