#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

// int dp[6][5]={0};

// int lcs(string s1,string s2){
// 	if(s1.length()==0 || s2.length()==0){
// 		return 0;
// 	}

// 	int count = 0;

// 	if(dp[s1.length()][s2.length()]!=0){
// 		return dp[s1.length()][s2.length()];
// 	}

// 	char ch1 = s1[0];
// 	string ros1 = s1.substr(1);
// 	char ch2 = s2[0];
// 	string ros2 = s2.substr(1);

// 	if(ch1==ch2){
// 		count = 1 + lcs(ros1,ros2);
// 	}else{
// 		int first = lcs(ros1,s2);
// 		int second = lcs(s1,ros2);

// 		count = max(first,second);
// 	}

// 	dp[s1.length()][s2.length()] = count;

// 	return count;
// }

int lcs_DP(string s1,string s2){

	int n = s1.length()+1;
	int m = s2.length()+1;

	int dp[n][m];

	for(int i = 0;i < n; i++){
		for(int j = 0; j < m; j++){

			if(i==0 or j==0){
				dp[i][j] = 0;
				continue;
			}

			if(s1[i-1]==s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}else{
				dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
			}

		}
	}

	return dp[n-1][m-1];
}

int Klcs(string s1,string s2,int k){
	if(s1.length()==0 || s2.length()==0){
		return 0;
	}

	int count = 0;

	// if(dp[s1.length()][s2.length()]!=0){
	// 	return dp[s1.length()][s2.length()];
	// }

	char ch1 = s1[0];
	string ros1 = s1.substr(1);
	char ch2 = s2[0];
	string ros2 = s2.substr(1);

	if(ch1==ch2){
		count = 1 + Klcs(ros1,ros2,k);
	}else{

		if(k>0){
			count = 1 + Klcs(ros1,ros2,k-1);
		}

		int first = Klcs(ros1,s2,k);
		int second = Klcs(s1,ros2,k);

		count = max(count,max(first,second));
	}

	// dp[s1.length()][s2.length()] = count;

	return count;
}

int dp[100][100] = {0};

int editDistance(string s1,string s2){
	if(s1.length()==0){
		return s2.length();
	}

	if(s2.length()==0){
		return s1.length();
	}

	if(dp[s1.length()][s2.length()]!=0){
		return dp[s1.length()][s2.length()];
	}

	char ch1 = s1[0];
	string ros1 = s1.substr(1);
	char ch2 = s2[0];
	string ros2 = s2.substr(1);

	int result = 0;

	if(ch1==ch2){
		result = editDistance(ros1,ros2);
	}else{

		int replace = 1 + editDistance(ros1,ros2);
		int deletion = 1 + editDistance(s1,ros2);
		int insertion = 1 + editDistance(ros1,s2);

		result = min(replace,min(deletion,insertion));
	}

	dp[s1.length()][s2.length()] = result;

	return result;
}

int editDistance_DP(string s1,string s2){

	int n = s1.length() + 1;
	int m = s2.length() + 1;

	int dp[n][m];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){

			if(i==0 or j==0){
				dp[i][j] = i + j;
				continue;
			}

			if(s1[i-1]==s2[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}else{
				int replace = dp[i-1][j-1];
				int del = dp[i][j-1];
				int ins = dp[i-1][j];

				dp[i][j] = min(replace,min(del,ins));
				dp[i][j]++;
			}
		}
	}

	return dp[n-1][m-1];
}

int optimalGame(int arr[],int i,int j){
	if(i > j){
		return 0;
	}

	int result;

	int first = arr[i] + min(optimalGame(arr,i+2,j),optimalGame(arr,i+1,j-1));
	int last = arr[j] + min(optimalGame(arr,i+1,j-1),optimalGame(arr,i,j-2));

	result = max(first,last);
	return result;
}

int main(){

	// cout<<lcs("abcde","agce")<<endl;

	// cout<<lcs_DP("abcde","agce")<<endl;

	// cout<<Klcs("abcde","agce",1)<<endl;

	// cout<<editDistance("abcde","agcd")<<endl;

	// cout<<editDistance_DP("abcde","agcd")<<endl;

	// int arr[] = {20, 30, 2, 2, 2, 10};
	// cout<<optimalGame(arr,0,5)<<endl;

	return 0;
}

// 8, 15, 3, 7  - > 22
//  20, 30, 2, 2, 2, 10 - > 42