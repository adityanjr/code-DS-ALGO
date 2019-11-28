#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<tuple<ll,ll,ll>>vec(10001);
vector<pair<ll,ll>>path(10001);
ll x;
ll b;
ll c;

bool possible(ll val){
     ll j = 0;
     bool ans = true;
     for(ll i = 0;i<b;i++){
         while(j<c && get<0>(vec[j])<=path[i].first){
             if(val>=get<1>(vec[j])) val += get<2>(vec[j]);
             j++;
         }
         if(val<=path[i].second){
             ans = false;
             break;
         }
         val -= path[i].second;
     }
     return ans;
}

int binarysearch(ll low, ll high){
    while(low<=high){
        ll mid =  low + (high-low)/2;
        if(possible(mid)){
            high=mid-1;
        }
        else
            low = mid+1;
    }
    return low;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        vec.clear();
        path.clear();
        cin>>x;
        cin>>b;
        for(int i=0;i<b;i++){
            ll m,n;
            cin>>m>>n;
            path.push_back({m,n});
        }
        cin>>c;
        ll ans = 0;

        for(int i=0;i<b;i++){
                ans += path[i].second;
            }
        ans++;

        if(c==0){
            cout<<ans<<endl;
        }
        else{
            for(ll i=0;i<c;i++){
                ll m,n,o;
                cin>>m>>n>>o;
                vec.push_back({m,n,o});
            }
            cout<<binarysearch(1,ans)<<endl;
        }
    }
    return 0;
}
