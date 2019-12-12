/*
link. https://codeforces.com/contest/339/problem/B
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{    unsigned long long int n,m;
     cin>>n>>m;
     unsigned long long int pos=1,sum=0,a[m],num=0;
     for(long int i=0;i<m;i++)
       {
         cin>>a[i];
         if(i!=0)
         {
             if(a[i-1]>a[i])
                num++;
         }
       }
       cout<<(num*n)+a[m-1]-1;
    return 0;
}
