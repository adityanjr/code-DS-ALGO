bool isValid(const vector<int> &A, const vector<int> &B, int med, int mid) {
    int n1 = upper_bound(A.begin(), A.end(), mid)-A.begin();
    int n2 = upper_bound(B.begin(), B.end(), mid)-B.begin();
    
    return (n1+n2>=med);
}
int getM(const vector<int> &A, const vector<int> &B, int med) {
    int l = min(A[0], B[0]);
    int r = max(A[A.size()-1], B[B.size()-1]);
    
    while(l<r) {
        long long mid = (l+r)>>1;
        if(isValid(A, B, med, mid))
            r = mid;
        else
            l = mid+1;
    }
    if(isValid(A, B, med, l))
        return l;
    return r;
}
double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n1 = A.size();
    int n2 = B.size();
    
    if(n1==0 && n2==0)
        return 0;
    if(n1==0) {
        if(n2%2==0)
            return ((double)B[n2/2]+(double)B[n2/2-1])/2.00;
        else
            return B[n2/2];
    }
    if(n2==0) {
        if(n1%2 ==0)
            return ((double)A[n1/2]+(double)A[n1/2-1])/2.00;
        else
            return A[n1/2];
    }
    
    int tot = (n1+n2);
    
    if(tot%2)
        return getM(A, B, tot/2+1);
    return ((double)getM(A, B, tot/2+1)+(double)getM(A, B, tot/2))/2.00;
}

