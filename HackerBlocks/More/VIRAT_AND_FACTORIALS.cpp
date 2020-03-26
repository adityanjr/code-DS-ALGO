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
	cin >> n;

	vector<int> ans;

	ans.pb(1);

	for(i=1;i<=n;i++){
		int carry=0;
		for(j=0;j<ans.size();j++){
			ans[j]=ans[j]*i+carry;
			carry=ans[j]/10;
			ans[j]=ans[j]%10;
		}
		while(carry){
			ans.pb(carry%10);
			carry/=10;
		}
	}
	for(i=ans.size()-1;i>=0;i--){
		cout << ans[i];
	}
	cout << endl;


	return 0;
}
