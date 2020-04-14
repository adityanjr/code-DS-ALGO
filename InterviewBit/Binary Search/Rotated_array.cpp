//  https://www.interviewbit.com/problems/rotated-array/

int Solution::findMin(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int index = 0;
    
    int l = 0, r = A.size()-1;
    if(A[l]<A[r])
        return A[0];
    if(A[r-1]>A[r])
        return A[r];
        
    while(l<=r) {
        int m = l+(r-l)/2;
        if(A[m-1]>A[m] && A[m]<A[m+1]) {
            index = m;
            break;
        }
        else if(A[0]>A[m])
            r = m-1;
        else
            l = m+1;
    }
    return A[index];
}

