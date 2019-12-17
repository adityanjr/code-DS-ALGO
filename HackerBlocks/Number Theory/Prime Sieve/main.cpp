#include <bits/stdc++.h>
using namespace std;
#define ll long long

void prime_sieve(ll n){
    ll p[n+1];
    memset(p,0,sizeof(p));
    p[0]=p[1]=0;
    p[2]=1;

    for(int i=3;i<=n;i+=2){
        p[i]=1;
    }
    for(int i=3;i<=n;i+=2){
     if(p[i]){
        for(int j=i*i;j<=n;j+=2*i){
               p[j]=0;
            }
        }
    }

    for(int i=2;i<=n;i++){
        if(p[i])
           cout<<i<<" ";
    }

}

int main() {

     ll n;
     cin>>n;
     prime_sieve(n);
     return 0;
}
