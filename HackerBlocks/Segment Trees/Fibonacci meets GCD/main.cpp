#include <iostream>
#include<vector>
using namespace std;
#define ll long long
#define MOD 1000000007
    ll N,Q;
    int k=2;
    int X,Y;
ll arr[100020];
vector<ll>vec(400100);

ll Extendedgcd(ll a, ll b){
    return (b==0)? a : Extendedgcd(b,a%b);
}


void buildtree(ll ss, ll se, ll index){

    if(ss==se){
        vec[index] = arr[se];
        return;
    }

    ll mid =  ss + (se-ss)/2;
    buildtree(ss,mid,2*index);
    buildtree(mid+1,se,2*index+1);
    vec[index] = Extendedgcd(vec[2*index],vec[2*index+1]);
    return;
}
   vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B){
        vector<vector<ll>>C(k+1,vector<ll>(k+1));
        for(int i=1;i<=k;i++){
            for(int j=1;j<=k;j++){
                for(int l=1;l<=k;l++){
                    C[i][j] = (C[i][j] + (A[i][l]*B[l][j])%MOD)%MOD;
                }
            }
        }
        return C;
    }

    vector<vector<ll>> power(vector<vector<ll>>T, ll n){
        if(n==1)
            return T;
        vector<vector<ll>>X = power(T,n/2);
        X = multiply(X,X);
        if(n&1)
           X = multiply(X,T);
        return X;
    }

ll query(ll ss, ll se, ll l , ll r, ll index){
    if(ss>r || se<l)
        return 0;

    if(ss>=l && se<=r){
        return vec[index];
    }

    ll mid = ss + (se-ss)/2;

    if(r<=mid)
        return query(ss,mid,l,r,2*index);

    ll left= query(ss,mid,l,r,2*index);
    ll right = query(mid+1,se,l,r,2*index+1);

    return Extendedgcd(left,right);
}

ll compute(ll n){
        if(n==1|| n==2){
            return 1;
        }
        vector<ll>F1(k+1);
        for(int i=1;i<=k;i++)
            F1[i]=1;
        vector<vector<ll>>T(k+1,vector<ll>(k+1));

        for(int i=1;i<=k;i++){
            for(int j=1;j<=k;j++){
              if(i<k){
                if(j==i+1)
                  T[i][j]=1;
                else
                T[i][j]=0;
              }
              else{
                T[i][j]=1;
              }
            }
        }

        T = power(T,n-1);
        ll val =0;
        for(int i=1;i<=k;i++){
            val = (val + (T[1][i]*F1[i])%MOD)%MOD;
        }
        return val;
    }

int main()
{
    ll n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>arr[i];
    buildtree(0,n-1,1);
    while(q--){
        ll l;
        ll r;
        cin>>l>>r;
        cout<<compute(query(0,n-1,l-1,r-1,1))<<endl;
    }
    return 0;
}
