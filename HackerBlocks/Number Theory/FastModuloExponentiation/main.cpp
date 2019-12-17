#include <iostream>
using namespace std;
#define ll long long

void fastmodExp(ll a, ll b){
    ll res =1;
    while(b>0){
        if(b&1){
            res = (res*a);
        }
        a = (a*a);
        b=b>>1;
    }

    cout<<res;
}
int main(){
    ll a,b,mod;
    cin>>a>>b>>mod;
    fastmodExp(a,b);
}
