//  https://www.interviewbit.com/problems/noble-integer/

int Solution::solve(vector<int> &A) {
    int m = A.size();
    sort(A.begin(), A.end());
    for(int i=0;i<m-1;i++)
    {
        if(A[i]==A[i+1])
            continue;
        if(A[i]==m-1-i)
            return 1;
    }
    if(A[m-1]==0)
        return 1;
    return -1;
    
}

