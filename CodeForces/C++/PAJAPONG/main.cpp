#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll t,x,y,k;
    cin>>t;
    while(t--){
        x=y=k=0;
        cin>>x>>y>>k;
        ll sum = x+y;
        ll ans = sum/k;
        if(ans&1)
            cout<<"Paja"<<endl;
        else
            cout<<"Chef"<<endl;
    }
    return 0;
}
