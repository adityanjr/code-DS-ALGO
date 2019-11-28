#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll t;
    ll n,c;
    cin>>t;
    while(t--){
        cin>>n>>c;
        ll arr[n];
        ll sum = 0 ;
        for(int i=0;i<n;i++) { cin>>arr[i]; sum += arr[i];}
        if(sum<=c)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
