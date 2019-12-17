#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void binaryStrings(ll a[], ll b[], ll n){
    if(n==1){
        a[n-1]=1;
        b[n-1]=1;
        return;
    }
    binaryStrings(a,b,n-1);
    a[n-1] = a[n-2]+b[n-2];
    b[n-1] = a[n-2];
}
int main()
{
    ll t,n;
    cin>>t;
    ll a[90],b[90];
    binaryStrings(a,b,90);
    while(t--){
        cin>>n;
        cout<<a[n-1]+b[n-1]<<endl;
    }
    return 0;
}
