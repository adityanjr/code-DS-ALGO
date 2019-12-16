#include <iostream>
#include<algorithm>
using namespace std;
#define ll long long int
int main()
{
    ll n,d;
    cin>>n>>d;
    ll arr[n];

    for(int i=0;i<n;i++) cin>>arr[i];

    sort(arr,arr+n);
    ll ans = 0;
    for(int i=0;i<n-1;i++){
        if(arr[i+1]-arr[i]<=d){
            ans++;
            i++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
