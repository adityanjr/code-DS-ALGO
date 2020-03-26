#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

// int dp[100] = {0,1};

//Recursive
int fibonacci(int n){
	if(n==1 || n==0){
		return n;
	}

	int fn1 = fibonacci(n-1);
	int fn2 = fibonacci(n-2);

	int fn = fn1 + fn2;
	return fn;
}

//Top Down
// int fib(int n){
// 	if(n==0 || n==1){
// 		return n;
// 	}
// 	if(dp[n]!=0){
// 		return dp[n];
// 	}
// 	int fn = fib(n-1) + fib(n-2);

// 	dp[n] = fn;
// 	return fn;
// }

//Bottom Up
int fibonacci_DP(int n){
	int dp[n+1];

	dp[0] = 0;
	dp[1] = 1;

	for(int i=2;i<=n;i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
}

//Recursive
int reduceToOne(int n){
	if(n==1){
		return 0;
	}
	int count1 = INT_MAX, count2 = INT_MAX, count3 = INT_MAX;

	if(n%3==0){
		count1 = 1 + reduceToOne(n/3);
	}
	if(n%2==0){
		count2 = 1 + reduceToOne(n/2);
	}
	count3 = 1 + reduceToOne(n-1);

	return min(count1, min(count2, count3));
}

//Top Down
// int dp[100] = {0};
// int reduceToOneOptimized(int n){
// 	if(n==1){
// 		return 0;
// 	}

// 	if(dp[n]!=0){
// 		return dp[n];
// 	}

// 	if(n%3==0){
// 		count1 = 1 + reduceToOneOptimized(n/3);
// 	}

// 	if(n%2==0){
// 		count2 = 1 + reduceToOneOptimized(n/2);
// 	}

// 	count3 = 1 + reduceToOneOptimized(n-1);

// 	dp[n] = min(count1,min(count2,count3));

// 	for(int i=1;i<=10;i++){
// 		cout<<dp[i]<<" ";
// 	}
// 	cout<<endl<<"************************* "<<n<<endl;
// 	return dp[n];
// }

//Bottom Up
int reduceToOne_DP(int n){
	int dp[n+1];

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for(int i=4;i<=n;i++){
		int count1 = INT_MAX,count2 = INT_MAX,count3 = INT_MAX;

		if(i%3==0){
			count1 = dp[i/3] + 1;
		}

		if(i%2==0){
			count2 = dp[i/2] + 1;
		}

		count3 = dp[i-1] + 1;

		dp[i] = min(count1,min(count2,count3));
	}

	return dp[n];
}


// int dp[100] = {0};

// int countBoardPathOptimized(int start,int end){

// 	if(start==end){
// 		return 1;
// 	}

// 	if(start>end){
// 		return 0;
// 	}

// 	if(dp[start]!=0){
// 		return dp[start];
// 	}

// 	int count = 0;

// 	for(int i=1;i<=6;i++){
// 		count+=countBoardPathOptimized(start+i,end);
// 	}

// 	dp[start] = count;

// 	for(int i=0;i<=10;i++){
// 		cout<<dp[i]<<" ";
// 	}
// 	cout<<endl<<"************************* "<<start<<endl;

// 	return dp[start];	
// }

int countBoardPath_DP(int start,int end){
	int dp[end+1];

	dp[end-1] = 1;
	dp[end] = 0;

	for(int i = end-2;i>=0;i--){
		dp[i] = 0;
		for(int dice = 1;dice<=6;dice++){
			if(i+dice>end){
				break;
			}

			dp[i]+=dp[i+dice];
		}
		if(i>= end - 6){
			dp[i]++;
		}

	}

	return dp[0];
}

int rodProfit(int arr[],int rodLength){
	if(rodLength==0){
		return 0;
	}

	int max_profit = INT_MIN;

	for(int i=1;i<=rodLength;i++){
		int temp_profit = arr[i-1] + rodProfit(arr,rodLength-i);
		max_profit = max(temp_profit,max_profit);
	}

	return max_profit;
}

int dp[100] = {0};

int rodProfitOptimized(int arr[],int rodLength){
	if(rodLength==0){
		return 0;
	}

	if(dp[rodLength]!=0){
		return dp[rodLength];
	}

	int max_profit = INT_MIN;

	for(int i=1;i<=rodLength;i++){
		int temp_profit = arr[i-1] + rodProfit(arr,rodLength-i);
		max_profit = max(temp_profit,max_profit);
	}

	dp[rodLength] = max_profit;

	return dp[rodLength];
}

int lis(int *arr,int n){
	int dp[n];

	// for(int i=0; i<n; i++) {
	// 	dp[i] = 1;
	// }

	fill(dp, dp+n, 1);

	int max_seq = INT_MIN;

	for(int i=1;i<n;i++){

		for(int j=0;j<i;j++){

			if(arr[j]<arr[i]){
				dp[i] = max(dp[j] + 1,dp[i]);
			}
		}
		max_seq = max(max_seq,dp[i]);
	}
	return max_seq;
}

int lisOptimised(int *arr, int n) {

	vector<int> v;
	v.push_back = arr[0];
	int maxLen = 1;
	for (int i = 1; i<=n; i++) {

		int curr = arr[i];
		auto start = v.begin(), end = v.end();
		auto it = upper_bound(start, end, curr);

		if (it == v.end()) {
			v.push_back(curr);
			maxLen++;
		}
		else {
			*it = curr;
		}
	}
	return maxLen;
}
int main(){

	// int n;
	// cin>>n;

	// cout<<fib(n)<<endl;
	// cout<<"*******************"<<endl;
	// cout<<fibonacci(n)<<endl;
	// cout<<"********************"<<endl;
	// cout<<fibonacci_DP(n)<<endl;

	// cout<<reduceToOne(10)<<endl;

	// cout<<reduceToOneOptimized(10)<<endl;

	// cout<<reduceToOne_DP(21)<<endl;

	// cout<<countBoardPathOptimized(0,10)<<endl;

	// cout<<countBoardPath_DP(0,10)<<endl;

	// int arr[] = {2,3,2,5};
	// cout<<rodProfit(arr,4)<<endl;
	// cout<<rodProfitOptimized(arr,4)<<endl;

	int arr[] = {3,10,2,22,5};
	cout << lis(arr, 5) << endl;
	cout << lisOptimised(arr, 5) << endl;

	return 0;
}