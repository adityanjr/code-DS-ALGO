#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;

        ll div = n/k;

        ll ans = div/k;

        ans *= k;

        if(ans!=div)
          cout<<"YES"<<endl;
        else
         cout<<"NO"<<endl;
    }
    return 0;
}
