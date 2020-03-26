#include<iostream>
using namespace std;
int main()
{
   int test;
   cin>>test;
   while(test--)
   {
   int minn,maxx,n,i,j;
   cin>>n;
   int a[n];
   cin>>minn>>maxx;
   for(i=0;i<n;i++)
   {
       cin>>a[i];
   }
   int freq[maxx+1]={0};
   for(i=0;i<n;i++)
   {
       freq[a[i]]++;
   }
   for(i=minn;i<=maxx;i++)
   {
       for(j=1;j<=freq[i];j++)
       {
           cout<<i<<" ";
       }
   }
   cout<<endl;
   }

   return 0;
}