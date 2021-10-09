#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;



#define ll              long long
#define pb              push_back
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n)       int *arr=new int[n];
#define t(x)            int t; cin>>t; while(t--)
#define fa(n)        for(int i=0; i<n; i++)
#define fr(n)           for(int j=n-1; j<=0; j--)fc
#define f(x,y)          for(int i=x; i<=y; i++)b
#define vi(v, n)        vector<long long> v(n);



void r_r_2() {
   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}




void solve() {
   ll n, count = 0;
   cin >> n;
   ll a[n];
   fa(n)
   cin >> a[i];
   fa(n) {
      if (a[i] > a[i + 1]) {
         count += a[i] - a[i + 1];
         a[i + 1] = a[i];
      }
   }
   cout << count;
}





int main()
{
   r_r_2();
   solve();
   return 0;
}