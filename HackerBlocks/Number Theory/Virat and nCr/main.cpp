#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long int
#define MAX 1000001
ll fact[MAX];

ll power(ll a,ll b){
    ll res = 1;
    a = a%MOD;
    while(b>0){
       if(b&1)
          res = ((res%MOD)*(a%MOD))%MOD;
        a = ((a%MOD)*(a%MOD))%MOD;
        b = b>>1;
    }
    return res%MOD;
}

int main(){
    ll n,r;
    cin>>n>>r;
    ll result = 1;
    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<MAX;i++){
        fact[i] = ((fact[i-1]%MOD)*(i%MOD))%MOD;
    }
    ll nfactorial = fact[n];
    ll nrfactorial = fact[n-r];
    ll rfactorial = fact[r];
    rfactorial = power(rfactorial,MOD-2);
    nrfactorial = power(nrfactorial,MOD-2);
    result = ((nfactorial%MOD)*(rfactorial%MOD))%MOD;
    result= ((result%MOD)*(nrfactorial%MOD))%MOD;
    cout<<result<<endl;
    return 0;
}
