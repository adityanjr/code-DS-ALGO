//  https://www.interviewbit.com/problems/sort-by-color/

void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size();
    
    int hash[3] = {0};
    
    for(int i=0;i<n;i++)
        hash[A[i]]++;
        
    int k = 0;
    for(int i=0;i<3;i++) {
        int j=0;
        while(j<hash[i]) {
            A[k++] = i;
            j++;
        }
    }
}


####### OR ###########

void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    sort(A.begin(), A.end());
}

