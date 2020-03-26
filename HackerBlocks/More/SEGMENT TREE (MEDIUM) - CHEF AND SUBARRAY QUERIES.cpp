// https://www.codechef.com/problems/CSUBQ
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
#define pll pair<ll,ll>
#define pb push_back

ll inf = 1e18;
ll mod = 1e9 + 7 ;
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}

struct treeNode{
  ll ans;
  ll len;
  ll prefixSubArrays;
  ll suffixSubArrays;

  treeNode(){
    ans=0ll;
    len=1ll;
    prefixSubArrays=0ll;
    suffixSubArrays=0ll;
  }
};

treeNode segtree[2][4*500000];


treeNode merge(treeNode leftChild,treeNode rightChild){
  treeNode ret;
  ret.len = leftChild.len + rightChild.len;
  ret.ans = leftChild.ans + rightChild.ans;
  ret.ans += leftChild.suffixSubArrays*rightChild.prefixSubArrays;

  ret.prefixSubArrays = leftChild.prefixSubArrays;  
  if(leftChild.prefixSubArrays == leftChild.len)
    ret.prefixSubArrays += rightChild.prefixSubArrays;

  ret.suffixSubArrays = rightChild.suffixSubArrays;
  if(rightChild.suffixSubArrays == rightChild.len)
    ret.suffixSubArrays += leftChild.suffixSubArrays;

  return ret;
}

void buildTree(ll treeNo,ll node,ll left,ll right,ll maxValue){
  if(left>right)return;
  if(left==right){
    segtree[treeNo][node].ans=1ll;
    segtree[treeNo][node].len=1ll;
    segtree[treeNo][node].prefixSubArrays=1ll;
    segtree[treeNo][node].suffixSubArrays=1ll;    
    return;
  }

  ll mid=left+right;
  mid/=2;
  buildTree(treeNo,2*node,left,mid,maxValue);
  buildTree(treeNo,2*node+1,mid+1,right,maxValue);
  segtree[treeNo][node]=merge(segtree[treeNo][2*node],segtree[treeNo][2*node+1]);
}

void updateTree(ll treeNo,ll node,ll left,ll right,ll maxValue,ll index,ll newValue){
  if(left>right or index<left or index>right)return;

  if(left==right){
    segtree[treeNo][node].len = 1ll;
    segtree[treeNo][node].ans = (newValue<maxValue);
    segtree[treeNo][node].prefixSubArrays = (newValue<maxValue);
    segtree[treeNo][node].suffixSubArrays = (newValue<maxValue);
    return;
  }

  ll mid=left+right;
    mid/=2;
  updateTree(treeNo,2*node,left,mid,maxValue,index,newValue);
  updateTree(treeNo,2*node+1,mid+1,right,maxValue,index,newValue);
  segtree[treeNo][node]=merge(segtree[treeNo][2*node],segtree[treeNo][2*node+1]);
}

treeNode query(ll treeNo,ll node,ll left,ll right,ll lf,ll rt){
  if(left>right or lf>right or rt<left){
    treeNode nnode;
    nnode.ans=0ll;
    nnode.len=0ll;
    nnode.prefixSubArrays = nnode.suffixSubArrays = 0ll;
    return nnode;
  }
  if(lf<=left and rt>=right)return segtree[treeNo][node];
  
  ll mid=(left+right)/2;
  
  treeNode leftChild = query(treeNo,2*node,left,mid,lf,rt);
  treeNode rightChild =  query(treeNo,2*node+1,mid+1,right,lf,rt);

  return merge(leftChild,rightChild);
}



int main()
{
  freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  // s(t);
  while(t--){
    ll n,q,L,R;
    s2(n,q);
    s2(L,R);
    buildTree(0,1,1,n,L);
    buildTree(1,1,1,n,R+1);

    while(q--){
      ll qtype;
      s(qtype);
      switch(qtype){
        case 1: ll x,y;
                s2(x,y);
                updateTree(0,1,1,n,L,x,y);
                updateTree(1,1,1,n,R+1,x,y);
               break;
        case 2: ll l,r;
                s2(l,r);
                ll ans = query(1,1,1,n,l,r).ans-query(0,1,1,n,l,r).ans;
                p(ans);
                break;
      }
    }
  }
  return 0;
 }