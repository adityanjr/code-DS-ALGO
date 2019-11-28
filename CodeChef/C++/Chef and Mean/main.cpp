#include <bits/stdc++.h>
using namespace std;
#define ll long long

double meanCalculator(ll k,ll arr[],ll n){
    double mean = 0.0;
    for(ll i=0;i<n;i++){
        if(i!=k){
           mean += (arr[i]/((n-1)*1.0));
        }
    }
    return mean;
}
int main()
{   string s1 = "Impossible";
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        ll arr[n];
        ll sum=0;
        float mean=0.0;
        bool flag = true;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        mean = sum/(n*(1.0));
        for(ll i=0;i<n;i++){
            float mean2 = meanCalculator(i,arr,n);
            if(mean2==mean){
                flag = false;
                cout<<i+1<<endl;
                break;
              }
        }
        if(flag)
          cout<<s1<<endl;
    }
    return 0;
}
