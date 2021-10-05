#include <iostream>
using namespace std;
#define ll long long

int main(){
    int t; cin>>t;
    while(t--){
        ll b, w, bc, wc, z;
        cin>>b>>w>>bc>>wc>>z;

        ll ans;
        if(wc+z <bc){
            ans = (b+w)*wc + b*z;
        }
        else if(bc+z <wc){
            ans = (b+w)*bc + w*z;
        }
        else {
            ans= b*bc + w*wc;
        }
        cout<<ans<<endl;
    }
}