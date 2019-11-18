#include<iostream>
#include<climits>
using namespace std;

int sum(int m[],int i,int j){
	int s = 0;
	for(int x=i;x<=j;x++){
		s += m[x];
		s = s%100;
	}
	return s%100;
}

int mixtures(int m[],int i,int j,int dp[][100]){
	if(i>=j){
		return dp[i][j]=0;
	}
	//rec case
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	int ans = INT_MAX;
	for(int k=i+1;k<=j;k++){
		int cans = mixtures(m,i,k-1,dp) + mixtures(m,k,j,dp) + sum(m,i,k-1)*sum(m,k,j);
		ans = min(ans,cans);
	}
	return dp[i][j]=ans;
}


int main(){

	int mix[] = {20,40,60};
	int n = sizeof(mix)/sizeof(int);

	int dp[100][100];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[i][j] = -1;
		}
	}

	cout<<"Ans "<<mixtures(mix,0,n-1,dp)<<endl;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}