//  https://www.interviewbit.com/problems/square-root-of-integer/

int Solution::sqrt(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    double n = A;
    double error = 0.00000001;
    double s = n;
    while((s - n/s) > error)
        s = (s + n/s)/2;
    return int(s);
}


######### OR ##########

int Solution::sqrt(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A<2)
        return A;
    
    long long int l=1, r=A/2, n = (long long) A;
    
    while(l<=r) {
        long long int m = l+(r-l)/2;
        if(m*m==n)
            return m;
        else if(m*m<n && (m+1)*(m+1)>n)
            return m;
        else if(m*m>n)
            r = m-1;
        else
            l = m+1;
    }
    return 0;
}

