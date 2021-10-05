#include<bits/stdc++.h>
using namespace std;

// Author - ADITYA SINGH (https://github.com/adityanjr)

#define ll              long long
#define pb              push_back
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n)       int *arr=new int[n];
#define t(x)            int x; cin>>x; while(x--)
#define f(x,y)          for(int i=x; i<=y; i++)


void c_p_c() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int main() {
	c_p_c();

	t(x) {
		vector<string>v1(4);
		vector<string>v2(4);
		f(0, 3) {
			cin >> v1[i];
		}
		f(0, 3) {
			cin >> v2[i];
		}
		int count = 0;
		f(0, 4) {
			for (int j = 0; j < 4; j++) {
				if (v1[i] == v2[j]) {
					count++;
				}
			}
		}
		if (count > 1) cout << "similar\n";
		else cout << "dissimilar\n";
	}

	return 0;

}