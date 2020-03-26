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

#define maxi 1000000
vector<ll> ar;
vector<ll> numOfDiv(maxi+5);

pll segTree[4*maxi+5];

void build(ll node,ll start,ll end){
  if(start>end)return;
  if(start==end){
    segTree[node].ff=ar[start];
    segTree[node].ss=ar[start];
    return ;
  }
  ll mid=(start+end)/2;
  build(2*node+1,start,mid);
  build(2*node+2,mid+1,end);
  segTree[node]=segTree[2*node+1];
  if(mid+1<=end){
    segTree[node].ff=max(segTree[node].ff,segTree[2*node+2].ff);
    segTree[node].ss+=segTree[2*node+2].ss;
  }
}

void update(ll node,ll start,ll end,ll lf,ll rt){
  if(start>end or start>rt or end<lf)return;
  if(start==end){
    ar[start]=numOfDiv[ar[start]];
    segTree[node].ff=ar[start];
    segTree[node].ss=ar[start];
    return ;
  }
  ll mid=(start+end)/2;
  if(segTree[2*node+1].ff>2)update(2*node+1,start,mid,lf,rt);
  if(mid+1<=end and segTree[2*node+2].ff>2)update(2*node+2,mid+1,end,lf,rt);
  segTree[node]=segTree[2*node+1];
  if(mid+1<=end){
    segTree[node].ff=max(segTree[node].ff,segTree[2*node+2].ff);
    segTree[node].ss+=segTree[2*node+2].ss;
  }
}

ll query(ll node,ll start,ll end,ll lf,ll rt){
  if(start>end or start>rt or end<lf)return 0ll;
  if(start>=lf and end<=rt) return segTree[node].ss;
  ll mid=(start+end)/2;
  return query(2*node+1,start,mid,lf,rt)+query(2*node+2,mid+1,end,lf,rt);
}

void pre(){
  numOfDiv[1]=1;
  for(int i=2;i<=maxi;i++)numOfDiv[i]=2;
  for(int i=2;i<=maxi;i++){
    for(int j=i*2;j<=maxi;j+=i)numOfDiv[j]++;
  }
}

int main()
{
   freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  pre();
  while(t--){
    ll n,q;
    s2(n,q);
    ar.resize(n);
    F(i,0,n-1)cin>>ar[i];
    build(0,0,n-1);
    while(q--){
      ll type,lf,rt;
      s3(type,lf,rt);
      lf--;
      rt--;
      if(type==1){
        update(0,0,n-1,lf,rt);
      }else{
        cout<<query(0,0,n-1,lf,rt)<<endl;
      }
    }

  }
  return 0;
 }