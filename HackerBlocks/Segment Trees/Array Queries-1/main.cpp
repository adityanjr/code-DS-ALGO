#include <iostream>
#include<vector>
#define ll long long int
using namespace std;
ll n;
ll k;
ll q;
ll T,L,R;
int arr[100020];
ll vec[400100];
ll lazy[400100]={0};

ll query(ll ss, ll se , ll l, ll r,ll index){

    if(lazy[index]){
        vec[index] += (se-ss+1)*lazy[index];
        if(ss!=se){
            lazy[2*index] += lazy[index];
            lazy[2*index+1] += lazy[index];
        }
        lazy[index] = 0;
    }

    if(ss>r || se<l){
        return 0;
    }

    if(ss>=l && se<=r){
        return vec[index];
    }

    ll mid = ss + (se-ss)/2;
    ll left;
    ll right;

    left = query(ss,mid,l,r,2*index);
    right = query(mid+1,se,l,r,2*index+1);

    return left + right;
}

void update(ll ss, ll se,ll l, ll r, ll index, ll val){

    if(lazy[index]){
        vec[index] += (se-ss+1)*lazy[index];
        if(ss!=se){
            lazy[2*index] += lazy[index];
            lazy[2*index+1] += lazy[index];
        }
        lazy[index] = 0;
    }

    if(ss>r || se<l){
        return;
    }

    if(ss>=l && se<=r){
        vec[index] += (se-ss+1)*val;
        if(ss!=se){
            lazy[2*index] += val;
            lazy[2*index+1] += val;
        }
        return;
    }

    ll mid = ss+(se-ss)/2;

    update(ss,mid,l,r,2*index,val);
    update(mid+1,se,l,r,2*index+1,val);
    vec[index] = vec[2*index]+vec[2*index+1];
    return;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>k>>q;
    for(int i=0;i<n;i++) {
     cin>>arr[i];
     ll l = i, r = i+k-1;
     if(r>=n){
        update(0,n-1,l,n-1,1,arr[i]);
        update(0,n-1,0,r-n,1,arr[i]);
     }
     else{
        update(0,n-1,l,r,1,arr[i]);
     }
    }

    while(q--){

        cin>>T>>L>>R;
        if(T==2){
            ll ans = query(0,n-1,L-1,R-1,1);
            cout<<ans<<endl;
        }
        else{
           ll l = L-1;
           ll r = L+ k-2;
           if(r>=n){
                update(0,n-1,l,n-1,1,R-arr[l]);
                update(0,n-1,0,r-n,1,R-arr[l]);
            }
          else{
                update(0,n-1,l,r,1,R-arr[l]);
            }
            arr[l] = R;
        }
    }
    return 0;
}
