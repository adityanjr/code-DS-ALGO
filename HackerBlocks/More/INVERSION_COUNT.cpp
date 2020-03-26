#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

int mergeCount(int arr[],int s,int m,int e){
	int temp[e-s+1];

	int i=s;
	int j=m+1;
	int k=0;
	int count=0;
	while(i<=m&&j<=e){
		if(arr[i]>arr[j]){
			temp[k++]=arr[j++];
			count+=(m-i+1);
		}else{
			temp[k++]=arr[i++];
		}
	}
	while(i<=m){
		temp[k++]=arr[i++];
	}
	while(j<=e){
		temp[k++]=arr[j++];
	}

	for(int i=s;i<=e;i++){
		arr[i]=temp[i-s];
	}

	return count;
}

int inversionCount(int arr[],int s,int e){
	if(s>=e){
		return 0;
	}
	if(s<e){
		int mid=(s+e)/2;

		int ans= inversionCount(arr,s,mid)+inversionCount(arr,mid+1,e)+mergeCount(arr,s,mid,e);
		return ans;
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

		cout << inversionCount(arr,0,n-1) << endl;
	}


	return 0;
}
