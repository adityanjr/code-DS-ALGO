//  https://www.interviewbit.com/problems/coin-sum-infinite/

int Solution::coinchange2(vector<int> &A, int B) {
    int n = A.size();
    vector<int> ways(B+1, 0);
    ways[0] = 1;
    
    for(int i=0;i<n;i++)
        for(int j=1;j<=B;j++)
            if(j >= A[i])
                ways[j] = (ways[j]+ways[j-A[i]])%1000007;
        
    return ways[B];
}

