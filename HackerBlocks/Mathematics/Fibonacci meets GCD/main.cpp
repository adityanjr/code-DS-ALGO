    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define MOD 1000000007
    ll N,Q;
    int k=2;
    int X,Y;

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

    ll Extendedgcd(ll A, ll B){
        if(B==0){
            X=1;
            Y=0;
            return A%MOD;
        }
        ll gcd = Extendedgcd(B,A%B);
        ll x1=Y;
        ll y1 = X - (A/B)*Y;
        X=x1;
        Y=y1;
        return gcd%MOD;
    }
    int main()
    {    cin>>N>>Q;
          ll L,R;
         ll arr[N];
         for(int i=0;i<N;i++)
            cin>>arr[i];
         while(Q--){
            cin>>L>>R;
            ll fiboValues[R-L+1];
            ll x = Extendedgcd(arr[L],fiboValues[L+1]);
            ll GCD = (x+MOD)%MOD;
            for(int i=L+2;i<=R;i++){
                ll x = Extendedgcd(GCD,arr[i])%MOD;
                GCD = (x+MOD)%MOD;
            }
            cout<<compute(GCD)<<endl;
         }
        return 0;
    }
