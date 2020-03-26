
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
	// The solution is very simple.
	// Just change the way you look at the question!
	// Rather than thinking in terms of segments, think what all segments each number could be
	// a part of. And that will solve the question in O(N) time.

	// Take a number, find its last occurence, then count the numbers between the number and its last
	// occurence, then simply mulitply it with the total count of numbers on its right hand side.
	// You are bascially adding 1 to all the ranges which consists of that number, each time you
	// do that.

	// freopen("input.txt","r",stdin);
 	// freopen("output.txt","w",stdout);
	ll t=1;
	//s(t);
	while(t--){
		ll n;
		s(n);
		vector<ll>ar(1000000+5,0);
		F(i,1,n)cin>>ar[i];
		ll ans=0ll;
		// Occ[z] will contain the array index where the number z was last found
		vector<ll> occ(1000000+5,0);
		F(i,1,n){
			ans+=(i-occ[ar[i]])*(n-i+1)*2 - 1ll;
			occ[ar[i]]=i;
		}
		double res = (double)(ans)/(double)(n*n);
		printf("%.6lf\n",res);
	}
}
