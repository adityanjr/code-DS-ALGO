//  https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/

int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    for(int i=0;i<A.size();i++) {
        if(i<A.size()-2 && A[i]!=A[i+1] && A[i]!=A[i+2])
            continue;
        else
            A.erase(remove(A.begin()+i+2, A.end(), A[i]), A.end());
    }
    
    return A.size();
}



####### OR #########

int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i=0, j=2;
    if(A.size()<=2)
        return A.size();
    while(j<A.size()) {
        if(A[i]==A[j]) {
            while(A[i]==A[j] && j<A.size())
                j++;
            A.erase(A.begin()+i, A.begin()+j-2);
            j = i+2;
        }
            
        else {
            i++;
            j++;
        }
    }
    return A.size();
}

