#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
typedef long long int ll;
ll n,k,c;
ll arr[N];
bool possible(ll val, ll k1){
     vector<ll>vec(val,0);
     int i = 0;
     while(k1--){
         int j = 0;
         while(i<n && j<val){
             if(vec[j]*c<=arr[i]){
                 vec[j++] = arr[i];
             }
             i++;
         }
         if(j < val){
             return false;
         }
     }
     return true;
}

int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        cin>>n>>k>>c;
        memset(arr,0,sizeof(arr));
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr,arr+n);
        ll l = 0;
        ll r = n; // it can be n/k or (n/k) + 1;
        ll answer=INT_MIN;
        while(l<=r){
            ll mid = l + (r-l)/2;
            if(possible(mid,k)){
                answer = mid; // it can be max(answer,mid);
                l = mid+1;
            }
            else
                r = mid - 1;
        }
        cout<<answer<<"\n";
    }
    return 0;
}
