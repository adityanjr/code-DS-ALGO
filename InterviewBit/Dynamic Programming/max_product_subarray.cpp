//  https://www.interviewbit.com/problems/max-product-subarray/

int Solution::maxProduct(const vector<int> &A) {
    int n = A.size();
    
    int curr_max_prod = A[0];
    int curr_min_prod = A[0];
    int prev_max_prod = A[0];
    int prev_min_prod = A[0];
    int ans = A[0];
    
    for(int i=1;i<n;i++) {
        curr_max_prod = max(prev_max_prod*A[i], max(prev_min_prod*A[i], A[i]));
        curr_min_prod = min(prev_max_prod*A[i], min(prev_min_prod*A[i], A[i]));
        ans = max(ans, curr_max_prod);
        prev_max_prod = curr_max_prod;
        prev_min_prod = curr_min_prod;
    }
    return ans;
}

