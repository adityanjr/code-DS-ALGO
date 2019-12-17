#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>arr(100005);
vector<ll>tree[400005];

void buildtree(ll ss, ll se,ll index){
    if(ss==se){
       tree[index].push_back(arr[ss]);
        return;
    }

    ll mid = ss + (se-ss)/2;
    buildtree(ss,mid,2*index);
    buildtree(mid+1,se,2*index+1);
    merge(tree[2*index].begin(),tree[2*index].end(), tree[2*index+1].begin(), tree[2*index+1].end(),back_inserter(tree[index]));
    return;
}

ll query(ll ss, ll se, ll l, ll r,ll value, ll index){
    if(ss>r || se<l || l>r){
        return 0;
    }

    if(ss>=l && se<=r){
        return tree[index].size() - (lower_bound(tree[index].begin(),tree[index].end(),value) - tree[index].begin());
    }

    ll mid = ss + (se-ss)/2;
    ll left = query(ss,mid,l,r,value,2*index);
    ll right = query(mid+1,se,l,r,value,2*index+1);
    return left+right;
}

int main() {
  ll n;
  cin>>n;
  for(ll i=0;i<n;i++)  cin>>arr[i];
  ll q;
  cin>>q;
  buildtree(0,n-1,1);
  while(q--){
      ll L,R,K;
      cin>>L>>R>>K;
      cout<<query(0,n-1,L-1,R-1,K,1)<<endl;
  }
}
