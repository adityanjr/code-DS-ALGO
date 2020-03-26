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

vector<ll> fibo(101,-1);
ll dp[102][102][2];

ll fib(ll n){
	if(n<0)return 0ll;
	if(n<=1)return 1ll;
	if(fibo[n]!=-1)return fibo[n];
	return fibo[n]=fib(n-1)+fib(n-2);
}

ll solve(ll lf,ll rt,vector<ll> &ar,ll player){
	if(lf==rt){
		if(player == 1) return fib(ar[lf]);
		else return 0LL;
	}
	// if(dp[lf][rt][player]!=-1)return dp[lf][rt][player];
	
	if(player==1){
		ll choice1 = fib(ar[lf])+solve(lf+1,rt,ar,0);
		ll choice2 = fib(ar[rt])+solve(lf,rt-1,ar,0);
		return dp[lf][rt][player] = max(choice1,choice2);
	}
	else {
		ll choice1 = solve(lf+1,rt,ar,1);
		ll choice2 = solve(lf,rt-1,ar,1);
		return dp[lf][rt][player] = min(choice1,choice2);		
	}
}

int main()
{
  freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  s(t);
  while(t--){
  	memset(dp,-1,sizeof(dp));
  	ll n;
  	s(n);
  	ll sum=0ll;
  	vector<ll>ar(n+1);
  	F(i,1,n){
  		cin>>ar[i];
  		sum+=fib(ar[i]);
  	}
  	ll player1 = solve(1,n,ar,1);
  	ll player2 = sum-player1;
  	cout<<player1<<" ";
  	if(player1==player2)cout<<"Tie\n";
  	else if(player1>player2)cout<<"First\n";
  	else cout<<"Second\n";
  }
 }