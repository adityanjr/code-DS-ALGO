//  https://www.interviewbit.com/problems/modular-expression/

long long int calMod(int A, int B, int C) {
    if(B==0)
        return 1;
    else if(B%2==0) {
        long long int y = calMod(A, B/2, C);
        return (y*y)%C;
    }
    else {
        return (calMod(A, B-1, C)*(A%C))%C;
    }
}
int Solution::Mod(int A, int B, int C) {
    if(A==0)
        return 0;
    int res = calMod(A, B, C);
    if(res<0)
        return C+res;
    else
        return res;
}

