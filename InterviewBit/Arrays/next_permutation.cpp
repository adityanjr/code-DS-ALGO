//  https://www.interviewbit.com/problems/next-permutation/#

void Solution::nextPermutation(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size()-1;
    int index, i;
    
    for(i=n;i>0;i--) {
        
        if(A[i]>A[i-1]) {
            index = i-1;
            break;
        }
        
    }
    if(i==0) {
        reverse(A.begin(), A.end());
        return;
    }
    i = n;
    while(A[index]>=A[i])
        i--;
    
    int temp = A[index];
    A[index] = A[i];
    A[i] = temp;
    
    sort(A.begin()+index+1, A.end());
    
}

