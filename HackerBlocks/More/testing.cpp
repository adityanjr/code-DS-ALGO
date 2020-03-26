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


int steps(int node, int moves, int des){
	if(node==des or node==-des)return moves;
	if(abs(node)>abs(des))return INT_MAX;

	int pos = steps(node+(moves+1),moves+1,des);
	int neg = steps(node-(moves+1),moves+1,des);
	return min(pos,neg);
}

int main()
{
   freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  s(t);
  while(t--){
  	ll des;
  	s(des);
  	cout<<steps(0,0,des)<<endl;
  	
  	// if(des==0){
  	// 	cout<<"0\n";
  	// 	continue;
  	// }
  	// queue<pair<int,int>>q;
  	// q.push({0,0});
  	// while(!q.empty()){
  	// 	pair<int,int> pii = q.front();
  	// 	q.pop();
  	// 	int num=pii.first;
  	// 	int moves=pii.second;
  	// 	if(num==des or num==-des){
  	// 		cout<<moves<<endl;
  	// 		break;
  	// 	}

  	// 	if(abs(num-(moves+1))<=abs(des))q.push({num-(moves+1),moves+1});
  	// 	if(abs(num+(moves+1))<=abs(des))q.push({num+(moves+1),moves+1});
  	// }
  }
  return 0;
 }