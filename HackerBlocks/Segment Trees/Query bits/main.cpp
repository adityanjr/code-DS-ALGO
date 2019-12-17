#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007ll
vector<ll>tree(800020);
vector<ll>lazyval(800020,-1);

ll pow(ll a, ll b, ll m = MOD){ // Power function
    ll res = 1;
    while(b>0){
        if(b&1){
            res = (res%m * a%m)%m;
        }
        a = (a%m*a%m)%m;
        b=b>>1;
    }
    return res;
}

void lazyup(ll ss,ll se,ll index){ // Lazy update function which assign 1 or 0 to particular range.
      if(lazyval[index]!=-1){
          tree[index] = (pow(2,se-ss+1,MOD)-1) * lazyval[index];
          if(ss!=se){
              lazyval[2*index] = lazyval[index];
              lazyval[2*index+1] = lazyval[index];
          }
          lazyval[index] = -1 ;
      }
}

void updaterange(ll ss, ll se, ll l ,ll r,ll index, ll val){

    lazyup(ss,se,index);

    if(ss>r || se<l){
        return;
    }

    if(ss>=l && se<=r){

         tree[index] = (pow(2,se-ss+1,MOD)-1)*val;
         if(ss!=se){
             lazyval[2*index] = val;
             lazyval[2*index+1] = val;
         }
         return;
    }

    ll mid = ss + (se - ss)/2;
    updaterange(ss,mid,l,r,2*index,val);
    updaterange(mid+1,se,l,r,2*index+1,val);

    tree[index]=(tree[2*index]*pow(2,se-mid,MOD)%MOD+ tree[2*index+1])%MOD;
    return;
}

ll query(ll ss, ll se, ll l, ll r, ll index){

     lazyup(ss,se,index);

    if(ss>r || se<l){
        return 0;
     }

     if(ss>=l && se<=r){
          return tree[index];
    }

    ll mid = ss + (se-ss)/2;
    ll left = 0;
    ll right = 0;

     left = query(ss,mid,l,r,2*index);
     right = query(mid+1,se,l,r,2*index+1);

    if(r<=mid)
      return left;

    return ((left%MOD*pow(2,min(se,r)-mid,MOD)%MOD)%MOD + right)%MOD;
}

int main() {
    ll n,q;
    cin>>n>>q;
    while(q--){
        ll T,L,R;
        cin>>T>>L>>R;
        if(T==1 || T==0)
            updaterange(0,n-1,L,R,1,T);
        else
            cout<<query(0,n-1,L,R,1)%MOD<<endl;
      }
    return 0;
}
