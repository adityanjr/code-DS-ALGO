#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

ll score[100005];

void alphascore(int arr[],int n){

	for(int i=1;i<n;i++){
		sort(arr,arr+i);
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i]){
				score[i]=(score[i]+arr[j])%mod;
			}
			else{
				break;
			}
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	#endif

	int i,j,k,len,n,sum,count;
	string str;
	int t;

	memset(score,0,sizeof(score));
	cin >> n;
	int arr[n];
	for(i=0;i<n;i++){
		cin >> arr[i];
	}

	alphascore(arr,n);

	ll ans = 0;

	for(i=1;i<n;i++){
		ans = (ans+score[i])%mod;
	}
	cout << ans << endl;



	return 0;
}
