//  https://www.interviewbit.com/problems/power-of-two-integers/

int Solution::isPower(int A) {
    if(A==1)
        return 1;
    for(int i=2;i<=sqrt(A);i++)
    {
        float p = i;
        while(p <= A)
        {
            p *= i;
            if(p == A)
                return 1;
 
        }
    }
    return 0;
}

