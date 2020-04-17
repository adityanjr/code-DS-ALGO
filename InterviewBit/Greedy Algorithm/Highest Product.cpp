//  https://www.interviewbit.com/problems/highest-product/

int Solution::maxp3(vector<int> &A) {
    sort(A.begin(), A.end());
    
    int ans = INT_MIN;
    int n = A.size();
    if(n<3)
        return 0;
    return max(A[0]*A[1]*A[n-1], A[n-1]*A[n-2]*A[n-3]);
}

