#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define fio ios_base::sync_with_stdio(false)
 
#define ll long long int

#define s(x) scanf("%lld",&x)
#define s2(x,y) s(x)+s(y)
#define s3(x,y,z) s(x)+s(y)+s(z)
 
#define p(x) printf("%lld\n",x)
#define p2(x,y) p(x)+p(y)
#define p3(x,y,z) p(x)+p(y)+p(z)
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define RF(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)
 
#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define pll pair<ll,ll>
#define pb push_back

ll inf = 1e18;
ll mod = 1e9 + 7 ;
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}

/**************************CODE GOES HERE*********************************************/

unordered_map<ll,vector<ll>> mapOfIndicesAtWhichChainTerminates;
unordered_map<ll,vector<ll>> mapOfIndicesAtWhichChainBegins;
unordered_map<ll,pll> mapOfFwdAndBwdChainOfEveryIndex;
vector<ll>ar;
ll ans=0ll;
ll n;


void insertInMap(ll idx,ll val){
  mapOfFwdAndBwdChainOfEveryIndex[idx]={-1,-1};
  mapOfIndicesAtWhichChainTerminates[val].pb(idx);
  mapOfIndicesAtWhichChainBegins[val].pb(idx);
  ans++;
  if(mapOfIndicesAtWhichChainTerminates[val-1].size()>0){
    ll fwdChainingWithIndex = mapOfIndicesAtWhichChainTerminates[val-1].back();
    mapOfIndicesAtWhichChainTerminates[val-1].erase(remove(mapOfIndicesAtWhichChainTerminates[val-1].begin(),mapOfIndicesAtWhichChainTerminates[val-1].end(),fwdChainingWithIndex),mapOfIndicesAtWhichChainTerminates[val-1].end());
    mapOfIndicesAtWhichChainBegins[val].erase(remove(mapOfIndicesAtWhichChainBegins[val].begin(),mapOfIndicesAtWhichChainBegins[val].end(),idx),mapOfIndicesAtWhichChainBegins[val].end());
    ans--;

    mapOfFwdAndBwdChainOfEveryIndex[idx].first=fwdChainingWithIndex;
    mapOfFwdAndBwdChainOfEveryIndex[fwdChainingWithIndex].second=idx;
  }

  if(mapOfIndicesAtWhichChainBegins[val+1].size()>0){
    ll bwdChainingWithIndex = mapOfIndicesAtWhichChainBegins[val+1].back();
    mapOfIndicesAtWhichChainTerminates[val].erase(remove(mapOfIndicesAtWhichChainTerminates[val].begin(),mapOfIndicesAtWhichChainTerminates[val].end(),idx),mapOfIndicesAtWhichChainTerminates[val].end());
    mapOfIndicesAtWhichChainBegins[val+1].erase(remove(mapOfIndicesAtWhichChainBegins[val+1].begin(),mapOfIndicesAtWhichChainBegins[val+1].end(),bwdChainingWithIndex),mapOfIndicesAtWhichChainBegins[val+1].end());
    ans--;

    mapOfFwdAndBwdChainOfEveryIndex[idx].second=bwdChainingWithIndex;
    mapOfFwdAndBwdChainOfEveryIndex[bwdChainingWithIndex].first=idx;
  }

}

void removeFromMap(ll idx,ll val){
  ll bwdChainedAt = mapOfFwdAndBwdChainOfEveryIndex[idx].first;
  ll fwdChainedAt = mapOfFwdAndBwdChainOfEveryIndex[idx].second;

  if(bwdChainedAt==-1){
    mapOfIndicesAtWhichChainBegins[val].erase(remove(mapOfIndicesAtWhichChainBegins[val].begin(),mapOfIndicesAtWhichChainBegins[val].end(),idx),mapOfIndicesAtWhichChainBegins[val].end());
  }else{
    mapOfIndicesAtWhichChainTerminates[val-1].pb(bwdChainedAt);
    mapOfFwdAndBwdChainOfEveryIndex[bwdChainedAt].second=-1;
    ans++;

    if(mapOfIndicesAtWhichChainBegins[val].size()>0){
      ll toChainForwardAtIndex = mapOfIndicesAtWhichChainBegins[val].back();
      mapOfIndicesAtWhichChainBegins[val].erase(remove(mapOfIndicesAtWhichChainBegins[val].begin(),mapOfIndicesAtWhichChainBegins[val].end(),toChainForwardAtIndex),mapOfIndicesAtWhichChainBegins[val].end());
      mapOfIndicesAtWhichChainTerminates[val-1].erase(remove(mapOfIndicesAtWhichChainTerminates[val-1].begin(),mapOfIndicesAtWhichChainTerminates[val-1].end(),bwdChainedAt),mapOfIndicesAtWhichChainTerminates[val-1].end());
      ans--;
      mapOfFwdAndBwdChainOfEveryIndex[bwdChainedAt].second=toChainForwardAtIndex;
      mapOfFwdAndBwdChainOfEveryIndex[toChainForwardAtIndex].first=bwdChainedAt;
    }

  }

  if(fwdChainedAt==-1){
    mapOfIndicesAtWhichChainTerminates[val].erase(remove(mapOfIndicesAtWhichChainTerminates[val].begin(),mapOfIndicesAtWhichChainTerminates[val].end(),idx),mapOfIndicesAtWhichChainTerminates[val].end());
    ans--;
  }else{
    mapOfIndicesAtWhichChainBegins[val+1].pb(fwdChainedAt);
    mapOfFwdAndBwdChainOfEveryIndex[fwdChainedAt].first=-1;

    if(mapOfIndicesAtWhichChainTerminates[val].size()>0){
      ll toChainBackwardAt = mapOfIndicesAtWhichChainTerminates[val].back();
      mapOfIndicesAtWhichChainTerminates[val].erase(remove(mapOfIndicesAtWhichChainTerminates[val].begin(),mapOfIndicesAtWhichChainTerminates[val].end(),toChainBackwardAt),mapOfIndicesAtWhichChainTerminates[val].end());
      mapOfIndicesAtWhichChainBegins[val+1].erase(remove(mapOfIndicesAtWhichChainBegins[val+1].begin(),mapOfIndicesAtWhichChainBegins[val+1].end(),fwdChainedAt),mapOfIndicesAtWhichChainBegins[val+1].end());
      ans--;
      mapOfFwdAndBwdChainOfEveryIndex[toChainBackwardAt].second=fwdChainedAt;
      mapOfFwdAndBwdChainOfEveryIndex[fwdChainedAt].first=toChainBackwardAt;
    }
  }

  mapOfFwdAndBwdChainOfEveryIndex[idx]={-1,-1};
}

void initMap(){
  F(i,1,n){
    insertInMap(i,ar[i]);
  }
}

int main()
{
   freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  // s(t);
  while(t--){
    
    s(n);
    ar=vector<ll>(n+1);
    F(i,1,n)cin>>ar[i];
    initMap();
    ll q;
    s(q);
    ll fin=0ll;
    F(i,1,q){
      ll indx,val;
      s2(indx,val);
      removeFromMap(indx,ar[indx]);
      // cout<<"Removed: "<<i<<" "<<ans<<endl;
      // F(i,1,n){
      //   cout<<"Index: "<<i<<" , backward linked to: "<<mapOfFwdAndBwdChainOfEveryIndex[i].first<<" , forward linked to: "<<mapOfFwdAndBwdChainOfEveryIndex[i].second<<endl;
      // }
      insertInMap(indx,val);
      // cout<<ans<<endl;
      ar[indx]=val;
      fin+=i*ans;
      fin%=mod;
      // cout<<"Inserted: "<<i<<" "<<ans<<endl;
      // F(i,1,n){
      //   cout<<"Index: "<<i<<" , backward linked to: "<<mapOfFwdAndBwdChainOfEveryIndex[i].first<<" , forward linked to: "<<mapOfFwdAndBwdChainOfEveryIndex[i].second<<endl;
      // }
      // cout<<endl;
    }
    p(fin);
  }
  return 0;
 }
