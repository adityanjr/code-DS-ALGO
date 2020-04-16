//  https://www.interviewbit.com/problems/single-number-ii/

int Solution::singleNumber(const vector<int> &A) {
    
    int n = A.size();
    int res = 0;
    
    for(int i=0;i<32;i++) {
        int bits = 0;
        for(int j=0;j<n;j++)
            if(A[j] & (1<<i))
                bits++;
        if(bits%3)
            res = res | (1<<i);
    }
    return res;
}

