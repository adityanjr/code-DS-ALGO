#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ll x,n;
    cin>>n;
    vector<ll>v;

    for(ll i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }

    if(n>=130){
        cout<<"YES";
        return 0;
    }
    else{
        for( ll i=0;i<n-3;i++){
          for(ll j=i+1;j<n-2;j++){
              for(ll k=j+1;k<n-1;k++){
                  for(ll l=k+1;l<n;l++){
                      if((v[i]^v[j]^v[k]^v[l])==0){
                         cout<<"YES";
                         return 0;
                      }
                  }
              }
          }
        }
    }

    cout<<"NO";

	return 0;
}
