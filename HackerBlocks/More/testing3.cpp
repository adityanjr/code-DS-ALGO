#include <string>
#include <cstdarg>
#include <utility>

#include <queue>
#include <stack>
#include <set>
#include <list>
#include <vector>
#include <queue>
#include <bitset>
#include <map>

#include <functional>
#include <sstream>
#include <algorithm>
#include <iostream>

#include <cstddef>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cstdio>


using namespace std;

#define ll long long int

#define s(x) scanf("%lld",&x)
#define s2(x,y) s(x)+s(y)
#define s3(x,y,z) s(x)+s(y)+s(z)

#define p(x) printf("%lld\n",x)
#define p2(x,y) p(x)+p(y)
#define p3(x,y,z) p(x)+p(y)+p(z)
#define fori(i,max) for(ll i=0;i<(ll)(max) ;(i)++)
#define for2i(i,min,max) for(ll i=min;i<(ll)(max) ;(i)++)

int main()
{
  freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  ll t;
  s(t);
  while(t--)
  {
    ll n,x;
    s2(n,x);
    ll *a=new ll[n+1];
    
    fori(i,n)
    {
      s(a[i]);
    }
    bool flag=0;

    // left pointer
    ll c1=0;

    // right pointer
    ll c2=0;

    // sum contains the sum of all the array elements between left and right pointer index
    ll sum=0;
    
    for(ll i=0;i<n;i++)
    {
      c2=i;
      sum+=a[c2];
      if(sum==x)
      {
        flag=1;break;
      }
      
      if(sum>x)
      {
        while(sum>=x && c1<=c2)
        {
        
          if(c1==c2)
          {
            sum=0;
            c1++;
            c2++;
            break;
          }
          
          sum -= a[c1];
          c1++ ;
        
          if(sum==x)
          {
            flag=1;break;
          }
        }
        if(flag==1)break;
      }
      
    }
    if(sum<x || flag==0)cout<<"NO\n";
    else cout<<"YES\n";
  }
  return 0;
}