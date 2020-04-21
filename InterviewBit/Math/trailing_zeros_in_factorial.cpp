//  https://www.interviewbit.com/problems/trailing-zeros-in-factorial/

int Solution::trailingZeroes(int A) {
    int n = 5;
    int count = 0;
    
    while(n<=A)
    {
        count += A/n;
        n *= 5;
    }
    return count;
}

