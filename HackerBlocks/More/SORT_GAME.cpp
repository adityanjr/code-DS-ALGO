#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

bool compare(pair<int,string> a,pair <int,string> b){
	if(a.first==b.first){
		return a.second<b.second;
	}

	return a.first>b.first;

}

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
	int x;

	cin >> x;

	cin >> n;

	vector<pair<int,string> > v(n);

	for(i=0;i<n;i++){
		cin >> v[i].second >> v[i].first;
	}

	sort(v.begin(),v.end(),compare);

	for(i=0;i<n;i++){
		if(v[i].first>=x){
			cout << v[i].second << " " << v[i].first << endl;
		}
	}


	return 0;
}
