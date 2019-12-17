#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){

    ll t,m,n;
    cin>>t;
    while(t--){
        cin>>m>>n;
        int size1 = sqrt((double)n);
        ll p[size1+1];
        fill(p,p+size1+1,1);
        p[0]=p[1]=0;
        for(ll i=2;i<=size1;i++){
            for(ll j=i*i; i<=size1;j+=i)
                p[j]=0;
        }

        for(ll i=0;i<=size1;i++)
             cout<<i<<" "<<p[i]<<endl;
    }
    return 0;
}
