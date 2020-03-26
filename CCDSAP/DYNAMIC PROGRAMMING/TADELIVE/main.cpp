
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll n,x,y;

    cin>>n>>x>>y;

    ll andy[n];
    ll bob[n];

    for(ll i=0;i<n;i++) cin>>andy[i];
    for(ll i=0;i<n;i++) cin>>bob[i];
    ll tip = 0;
    ll andyorders = 0;
    ll boborders = 0;
    for(ll j=0;j<n;j++){
         if(andy[j]>bob[j]){
           if(andyorders+1<=x){
                tip += andy[j];
                andyorders++;
           }
           else{
               tip += bob[j];
               boborders++;
           }
         }
         else{
             if(boborders+1<=y){
                tip += bob[j];
                boborders++;
           }
           else{
               tip += andy[j];
               andyorders++;
           }
         }
    }
    cout<<tip<<endl;
}
