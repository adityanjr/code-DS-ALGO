//  https://www.interviewbit.com/problems/grid-unique-paths/

int Solution::uniquePaths(int A, int B) {
    long long ans = 1;
    for(int i=B;i<A+B-1;i++)
    {
        ans *= i;
        ans /= (i-B+1);
    }
    return int(ans);
}

