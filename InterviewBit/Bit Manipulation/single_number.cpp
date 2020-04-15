//  https://www.interviewbit.com/problems/single-number/

int Solution::singleNumber(const vector<int> &A) {
    int x = A[0];
    int n = A.size();
    
    for(int i=1;i<n;i++)
        x = x^A[i];
        
    return x;
}

