//  https://www.interviewbit.com/problems/diffk-ii/

int Solution::diffPossible(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size()<2)
        return 0;
    
    unordered_map<int, int> hash;
    
    for(int i=0;i<A.size();i++)
        hash[A[i]]++;
        
    for(int i=0;i<A.size();i++) {
        int k = A[i]-B;
        if(k>=0) {
            if(B==0) {
                if(hash[k]>1)
                    return 1;
            }
            else if(hash[k]>0)
                return 1;
        }
        
    }
    return 0;
}

