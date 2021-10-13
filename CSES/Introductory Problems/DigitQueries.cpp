//problem : https://cses.fi/problemset/task/2431
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define  rep(i,a,b)    for(ll i = a; i<b ; i++)  
#define   PB    push_back
#define   MP    make_pair
#define   PI    3.141592653589
#define   mod   1000000007 
#define   MAX   1000001 

ll power(ll a, ll b) // result given in form of modulo 10^9+7
{
    ll result =1;
    while(b)
    {   if(b%2) result=(result*a);    //O(logn) 
        a=(a*a);
        b/=2;}
    return result;
}
 
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
    int T;cin>>T; 
    for(int test=1;test<=T;test++)
    {
        ll k; cin>>k;
        if(k<=9) 
        {     cout<<k<<"\n";
              continue;
        }
        ll temp=k;
        int digit =1;
        k-=9; digit++;
        for(int i=2;k>0;i++)
        {
            temp=k;
            k-=((9*i)*power(10,i-1));
            digit++;
        }
        if(k==0){
          cout<<"9\n";
          continue;
        }
        ll cnt = temp/(digit-1);
        ll pos = temp%(digit-1);
        if(pos==0)
        {
            cout<<(power(10,digit-1)+cnt-1)%10<<"\n";
            continue;
        }
        ll num= power(10,digit-2)+cnt;
        int ans =0;
        for(int i=1;i<=(digit-pos);i++)
        {
            ans=num%10;
            num=num/10;
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}
