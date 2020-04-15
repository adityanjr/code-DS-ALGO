//  https://www.interviewbit.com/problems/number-of-1-bits/

int Solution::numSetBits(unsigned int n) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int count = 0;
    
    while(n) {
        n = n&(n-1);
        count++;
    }
    return count;
}


######### OR #########

int Solution::numSetBits(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int bits = 0;
    
    for(int i=0;i<32;i++)
        if(A&(1<<i))
            bits++;
    return bits;
}

