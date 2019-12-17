#include <iostream>
using namespace std;
#define ll long long

ll breaknumber(ll a, string m){
      ll mod=0;
    for(int i=0; i < m.size();i++){
        mod = (mod*10 + (m[i]-'0'))%a;
    }
    return mod;
}

ll gcd(ll a, ll b){
if(a==0)
    return b;
return gcd(b%a,a);
}
void largegcd(ll n, string m){
    ll M = breaknumber(n,m);
    cout<<gcd(n,M);
}
int main()
{   string m;
    ll n;
    cin>>n>>m;
    largegcd(n,m);
    return 0;
}
