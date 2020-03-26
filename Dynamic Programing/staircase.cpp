#include<iostream>
using namespace std;

//bottom up
int ways(int n,int k){

	int dp[100] = {0};
	dp[0] =1;
	for(int i=1;i<=n;i++){
		dp[i] = 0;
		for(int jump=1;jump<=k;jump++){
			if(i-jump>=0){
				dp[i] += dp[i-jump];
			}
		}
	}
	return dp[n];
}

int main(){
	int n,k;
	cin>>n>>k;
	cout<<ways(n,k)<<endl;

	return 0;
}