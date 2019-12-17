#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll X,Y;
void multiplicativemoduloinverse(ll A, ll M){
    if(M==0){
        X=1;
        Y=0;
        return;
    }
    multiplicativemoduloinverse(M,A%M);
    ll Cx = Y;
    ll Cy = (X - (A/M)*Y);

    X=Cx;
    Y=Cy;
}


int main(){
    ll k;
    cin>>k;
    ll num[k],rem[k],pp[k],inv[k];
    ll prod = 1;

    for(int i=0;i<k;i++){
         cin>>num[i];
         prod *= num[i];
    }
    for(int i=0;i<k;i++){
        cin>>rem[i];
    }

    for(int i=0;i<k;i++){
        pp[i] = prod/num[i];
        multiplicativemoduloinverse(pp[i],num[i]);
        inv[i] = (X%num[i] + num[i])%num[i];
    }
  ll x=0;
  for(int i=0;i<k;i++){
        x += ((rem[i]*pp[i]*inv[i]))%prod;
  }
  cout<<x%prod<<endl;
  return 0;
}
