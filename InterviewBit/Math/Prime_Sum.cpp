//  https://www.interviewbit.com/problems/prime-sum/

int isPrime(int n)
{
    for(int i=3;i<=sqrt(n);i++)
        if(n%i==0)
            return 0;
    return 1;
}
vector<int> Solution::primesum(int A) {
    vector<int> nums;
    if(A==4)
    {
        nums.push_back(2);
        nums.push_back(2);
        return nums;
    }
    for(int i=3;i<A;i+=2)
        if(isPrime(i) && isPrime(A-i))
        {
            nums.push_back(i);
            nums.push_back(A-i);
            break;
        }
    return nums;
}

