#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void pairingProblem(ll a[], ll n){
       if(n==1){
           a[n]=1;
           return;
       }
       pairingProblem(a,n-1);
       a[n] = a[n-1] + (n-1)*a[n-2];

}
int main()
{
    ll t,n;
    cin>>t;
    ll a[31];
    a[0]=1;
    pairingProblem(a,30);
    while(t--){
        cin>>n;
        cout<<a[n]<<endl;
    }
    return 0;
}
