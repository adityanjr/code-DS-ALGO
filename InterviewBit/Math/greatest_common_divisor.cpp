//  https://www.interviewbit.com/problems/greatest-common-divisor/ 

int Solution::gcd(int n, int m) {
    while(m!=0)
    {
        int r = n%m;
        n = m;
        m = r;
    }
    return n;
}

