//  https://www.interviewbit.com/problems/rotate-matrix/

void Solution::rotate(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
            swap(A[i][j], A[j][i]);
                
    
    
    for(int i=0;i<n;i++) 
        for(int j=0;j<n/2;j++)
            swap(A[i][j], A[i][n-j-1]);
    
}

