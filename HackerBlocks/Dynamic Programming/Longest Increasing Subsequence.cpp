#include<iostream>
#include<vector>
using namespace std;
// O(n^2) approach
int longestIncreasingSubsequence(vector<int> arr) {
      int dp[arr.size()];
      for(int i=0;i<arr.size();i++){
          dp[i] = 1;
      }

      int ans = -1;
      for(int i=1;i<arr.size();i++){
          int best = 0;
          for(int j=0;j<i;j++){
               if(arr[i]>arr[j]){
                 best = max(best,dp[j]);
               }
          }
          dp[i] =  max(best+1,dp[i]);
          ans = max(dp[i],ans);
      }
      return ans;
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	cout<<longestIncreasingSubsequence(arr)<<endl;
	return 0;
}