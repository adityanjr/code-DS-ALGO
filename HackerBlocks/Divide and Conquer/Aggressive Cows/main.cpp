#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n,c;
ll arr[100005];

int fn(ll space){
    ll temp = 1;
    ll prev = arr[0];
    for(ll i=1;i<n;i++){
        if(arr[i]-prev>=space){
            temp++;
            if(temp==c)
                return 1;
            prev = arr[i];
        }
    }
   return 0 ;
}
void binarysearch(){
    ll l = arr[0];
    ll r = arr[n-1];
    while(l<=r){
        ll mid = l + (r-l)/2;
        if(fn(mid)){
            l  = mid + 1;
        }
        else{
            r = mid -1 ;
        }
    }
   cout<<l-1;
}
int main()
{
    cin>>n>>c;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    binarysearch();
    return 0;
}
