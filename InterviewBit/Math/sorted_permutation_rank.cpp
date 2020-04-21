//  https://www.interviewbit.com/problems/sorted-permutation-rank/

int d=1000003;
int fac[1000000];
  string B;
  int frank(char c)
  {
      int rank=B.find(c);
       B.erase(remove(B.begin(), B.end(), c), B.end());
       return rank;
  }
int Solution::findRank(string A) {
    int s=1;    int n = A.size();
    fac[0]=1;
    for(int i=1;i<n;i++)
    {
        s*=i;
        if(s>=d)
         s=s%d;
        fac[i]=s;
    }
     B= A;
    sort(B.begin(), B.end());
    if(B==A)
        return 1;
    int i=0;
    long long count=0;    int t=0;

   for(int i=0;i<n;i++)
   {
       count+=(frank(A[i]))*(fac[n-1-i]);
   }
    return (count+1)%1000003;
}
