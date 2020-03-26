#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

int maxSum(int arr[],int s,int m,int e){

	int sum=0;
	int maxLeftSum=INT_MIN;
	for(int i=m;i>=s;i--){
		sum+=arr[i];
		maxLeftSum=max(maxLeftSum,sum);
	}
	sum=0;
	int maxRightSum=INT_MIN;
	for(int i=m+1;i<=e;i++){
		sum+=arr[i];
		maxRightSum=max(maxRightSum,sum);
	}

	return maxLeftSum + maxRightSum;
}

int findMaxSubarraySum(int arr[],int s,int e){
	if(s==e){
		return arr[s];
	}
	else{
		int m=(s+e)/2;

		int left=findMaxSubarraySum(arr,s,m);
		int right=findMaxSubarraySum(arr,m+1,e);
		int both = maxSum(arr,s,m,e);

		return max(left,max(right,both));
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

	cin >> t;

	while(t--)
	{
		cin >> n;
		int arr[n];
		for(i=0;i<n;i++){
			cin >> arr[i];
		}

		cout << findMaxSubarraySum(arr,0,n-1) << endl;;
	}


	return 0;
}
