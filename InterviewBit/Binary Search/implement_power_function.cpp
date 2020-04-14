//  https://www.interviewbit.com/problems/implement-power-function/

int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(x==0)
        return 0;
    
    if(n==0)
        return 1;
        
    int flag = 0;
    long long int rem = 1, temp;
    
    if(x<0) {
        x = abs(x);
        if(n%2) 
            flag = 1;
    }
    temp = x%d;
    while(n) {
        
        if(n%2) {
            rem = (rem*temp)%d;
            n--;
        }
        
        temp = (temp*temp)%d;
        n = n/2;
    }
    
    if(flag) {
        return (d - rem);
    }
    
    return rem;
}

