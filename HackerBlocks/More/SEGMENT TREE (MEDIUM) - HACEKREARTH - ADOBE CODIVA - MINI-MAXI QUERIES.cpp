// https://www.hackerrank.com/contests/adobe-codiva/challenges/mini-maxi-queries/problem

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

ll inf = 1e9;
ll mod = 1e9 + 7 ;
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}

/****************************************************************************/

struct tnode{
  ll lfid0;
  ll rtid0;
  ll lfid1;
  ll rtid1;
  ll mindis0;
  ll maxdis0;
  ll mindis1;
  ll maxdis1;
  tnode(){
    lfid0=-1;
    rtid0=-1;
    lfid1=-1;
    rtid1=-1;
    mindis0=inf;
    maxdis0=-1;
    mindis1=inf;
    maxdis1=-1;
  }
}segTree[200000+5];

vector<int> lazy(200000+5,0);

tnode mergeNodes(tnode leftNode,tnode rightNode){
    tnode newNode;
    if(leftNode.lfid0!=-1)newNode.lfid0=leftNode.lfid0;
    else newNode.lfid0=rightNode.lfid0;

    if(leftNode.lfid1!=-1)newNode.lfid1=leftNode.lfid1;
    else newNode.lfid1=rightNode.lfid1;
    
    if(rightNode.rtid0!=-1)newNode.rtid0=rightNode.rtid0;
    else newNode.rtid0=leftNode.rtid0;

    if(rightNode.rtid1!=-1)newNode.rtid1=rightNode.rtid1;
    else newNode.rtid1=leftNode.rtid1;

    newNode.mindis0=min(leftNode.mindis0,rightNode.mindis0);
    if(leftNode.rtid0!=-1 and rightNode.lfid0!=-1)
      newNode.mindis0=min(newNode.mindis0,rightNode.lfid0-leftNode.rtid0);

    newNode.mindis1=min(leftNode.mindis1,rightNode.mindis1);
    if(leftNode.rtid1!=-1 and rightNode.lfid1!=-1)
      newNode.mindis1=min(newNode.mindis1,rightNode.lfid1-leftNode.rtid1);

    newNode.maxdis0=max(leftNode.maxdis0,rightNode.maxdis0);
    if(leftNode.lfid0!=-1 and rightNode.rtid0!=-1)
      newNode.maxdis0=max(newNode.maxdis0,rightNode.rtid0-leftNode.lfid0);

    newNode.maxdis1=max(leftNode.maxdis1,rightNode.maxdis1);
    if(leftNode.lfid1!=-1 and rightNode.rtid1!=-1)
      newNode.maxdis1=max(newNode.maxdis1,rightNode.rtid1-leftNode.lfid1);
    
    return newNode;
}

void buildTree(ll node,ll lf,ll rt){
  if(lf>rt)return;
  if(lf==rt){
    tnode leaf;
    leaf.lfid0=lf;
    leaf.rtid0=lf;
    segTree[node]=leaf;
    return;
  }
  ll mid=(lf+rt)/2;
  buildTree(2*node,lf,mid);
  buildTree(2*node+1,mid+1,rt);
  segTree[node]=mergeNodes(segTree[2*node],segTree[2*node+1]);
}

void lazyUpdate(ll node,ll lf,ll rt,ll beg,ll end){
  if(lazy[node]){
    swap(segTree[node].lfid0,segTree[node].lfid1);
    swap(segTree[node].rtid0,segTree[node].rtid1);
    swap(segTree[node].mindis0,segTree[node].mindis1);
    swap(segTree[node].maxdis0,segTree[node].maxdis1);
    lazy[node]=0;
    if(lf!=rt){
      lazy[2*node]=lazy[2*node]^1;
      lazy[2*node+1]=lazy[2*node+1]^1;
    }
  }
  if(lf>rt or lf>end or rt<beg)return;
  if(lf>=beg and rt<=end){
    swap(segTree[node].lfid0,segTree[node].lfid1);
    swap(segTree[node].rtid0,segTree[node].rtid1);
    swap(segTree[node].mindis0,segTree[node].mindis1);
    swap(segTree[node].maxdis0,segTree[node].maxdis1);
    if(lf!=rt){
      lazy[2*node]=lazy[2*node]^1;
      lazy[2*node+1]=lazy[2*node+1]^1;
    }
    return;
  } 
  ll mid=(lf+rt)/2;
  lazyUpdate(2*node,lf,mid,beg,end);
  lazyUpdate(2*node+1,mid+1,rt,beg,end);
  segTree[node]=mergeNodes(segTree[2*node],segTree[2*node+1]);
  return;
}

tnode lazyQuery(ll node,ll lf,ll rt,ll beg,ll end){
  if(lazy[node]){
    swap(segTree[node].lfid0,segTree[node].lfid1);
    swap(segTree[node].rtid0,segTree[node].rtid1);
    swap(segTree[node].mindis0,segTree[node].mindis1);
    swap(segTree[node].maxdis0,segTree[node].maxdis1);
    lazy[node]=0;
    if(lf!=rt){
      lazy[2*node]=lazy[2*node]^1;
      lazy[2*node+1]=lazy[2*node+1]^1;
    }
  }

  tnode dumbNode;
  if(lf>rt or lf>end or rt<beg)return dumbNode;
  
  if(lf>=beg and rt<=end) return segTree[node];
  
  ll mid=(lf+rt)/2;
  tnode leftNode = lazyQuery(2*node,lf,mid,beg,end);
  tnode rightNode = lazyQuery(2*node+1,mid+1,rt,beg,end);
  return mergeNodes(leftNode,rightNode);
}



int main()
{
  freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  // s(t);
  while(t--){
    ll n,q;
    s2(n,q);
    buildTree(1,1,n);
    // tnode tno;
    // cout<<tno.maxdis1<<" "<<tno.mindis1<<" "<<tno.lfid0<<endl;
    // return 0;
    while(q--){
      ll type;
      s(type);
      if(type==1){
        ll l,r,val;
        s3(l,r,val);
        if(val==1)lazyUpdate(1,1,n,l,r);
      }else {
        ll l,r;
        s2(l,r);
        tnode resNode = lazyQuery(1,1,n,l,r);
        if(resNode.mindis1==inf) resNode.mindis1=-1;
        if(type==2) cout<<resNode.mindis1<<endl;
        else cout<<resNode.maxdis1<<endl;
      }
    }
  }
  return 0;
 }