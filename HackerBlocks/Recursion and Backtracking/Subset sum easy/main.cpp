#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool printYES = false;

void subset(ll arr[],ll n,ll pos, vector<ll>v){
    if(pos==n && printYES==false){
      if(v.size()>0){
          ll sum=0;
          for(ll i=0;i<v.size();i++)
               sum += v[i];
         if(sum==0){
            cout<<"Yes"<<endl;
            printYES = true;
         }
     }
     return;
    }
    v.push_back(arr[pos]);
    subset(arr,n,pos+1,v);
    v.pop_back();
    subset(arr,n,pos+1,v);
}
int main()
{
    ll t,n;
    ll arr[10];
    cin>>t;
    vector<ll>v;
    while(t--){
        cin>>n;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        subset(arr,n,0,v);
        if(!printYES)
            cout<<"No"<<endl;
        v.clear();
    }
    return 0;
}
