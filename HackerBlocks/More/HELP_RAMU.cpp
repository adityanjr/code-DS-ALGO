#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	#endif

	int i,j,k,len,n,sum,count;
	string str;
	int t;
	int c1,c2,c3,c4;
	int m;
	cin >> t;

	while(t--){
		cin >> c1 >> c2 >> c3 >> c4;

		cin >> n >> m;

		int rickshaw[n],cab[m];
		int rickcost=0,cabcost=0;
		for(i=0;i<n;i++){
			cin >> rickshaw[i];
			rickcost+=min(rickshaw[i]*c1,c2);
		}
		for(i=0;i<m;i++){
			cin >> cab[i];
			cabcost+=min(cab[i]*c1,c2);
		}
		int ans = min(rickcost,c3)+min(cabcost,c3);
		ans = min(ans,c4);

		cout << ans << endl;
	}


	return 0;
}
