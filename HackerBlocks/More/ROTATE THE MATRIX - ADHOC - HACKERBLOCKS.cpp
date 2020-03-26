// https://csacademy.com/contest/archive/task/matrix_rotations/statement/
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

int main()
{
	// freopen("input.txt","r",stdin);
 	// freopen("output.txt","w",stdout);
	ll t=1;
	//s(t);
	while(t--){	
		ll n;
		s(n);
		vector<vector<ll>> a(n+1);
		F(i,1,n){
			a[i].resize(n+1);
			F(j,1,n){
				cin>>a[i][j];
			}
		}

		F(i,1,n){
			F(j,1,n){
				// Basic Observation
				ll res = a[i][j]|a[j][n-i+1]|a[n-j+1][i]|a[n-i+1][n-j+1];
				cout<<res<<" ";
			}
			cout<<endl;
		}
	}
}
