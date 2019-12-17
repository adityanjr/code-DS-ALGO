#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll power(ll a,ll p, ll MOD){
    ll res=1;
    a = a%MOD;
    while(p>0){
        if(p&1)
            res = (res*a)%MOD;
        a = (a*a)%MOD;
        p=p>>1;
    }
    return res;
}

ll gcd(ll a, ll b){
    if(a<b)
        return gcd(b,a);
    else if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}

bool check_prime(ll p){
    if(p<=1 || p==4)
        return false;
    if(p<4)
        return true;
    ll k = 100;
    while(k--){
        ll a = 2+rand()%(p-4);

        if(gcd(a,p)!=1)
            return false;

        if(power(a,p-1,p)!=1)
            return false;
    }
    return true;
}
int main()
{
    ll p,t;
    cin>>t;
    while(t--){
    cin>>p;
    if(check_prime(p))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    }
    return 0;
}
