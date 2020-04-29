//  https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/

int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details


    for(int i=1;i<A.size();i++) {
        if(A[i]==A[i-1])
            A.erase(remove(A.begin()+i, A.end(), A[i]), A.end());
    }
    return A.size();
}



####### OR ########

int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details


    int n = A.size();
    int i=0, j=1;
    if(n<=1)
        return n;
    while(j<A.size()) {
        if(A[i]!=A[j]) {
            i++;
            j++;
        }
        else {
            while(A[i]==A[j] && j<A.size())
                j++;
            A.erase(A.begin()+i, A.begin()+j-1);   
            j = i+1;
        }
    }
    return A.size();
}



########## OR ##########


int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i=0, j=1;
    while(j<A.size()) {
        if(A[i]!=A[j]) {
            ++i;
            A[i] = A[j];
        }
        else 
            ++j;
    }
    return i+1;
}


########## OR ############


int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    A.erase(unique(A.begin(), A.end()), A.end());
    return A.size();
}

