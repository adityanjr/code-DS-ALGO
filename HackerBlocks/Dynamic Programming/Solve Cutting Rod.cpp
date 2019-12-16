#include <iostream>
using namespace std;
int memo[100]={-1};
int dp[100]={-1};

//Using bottom up approach
// Nested loop is not dependent upon the dimensions of array.
void usingbottomup(int arr[],int totallen){
    dp[0]=0;
    for(int i=1;i<=totallen;i++){
        int best = 0;
        for(int j = 1;j<=i;i++){
            int ans  = arr[j] + dp[i-j];
            best = max(best,ans);
        }
        dp[i] = best;
    }
}
//Memoization. 
int maxProfit(int arr[], int totallen){
    if(totallen<=0) return 0;

    if(memo[totallen]!=-1) return memo[totallen];
    int best = 0;
    for(int i=1;i<=totallen;i++){
         int ans = arr[i] + maxProfit(arr,totallen-i);
         best = max(best,ans);
    }
    memo[totallen] = totallen;
    return best;
}

int main() {
    
    int totallen;
    cin>>totallen;

    int priceofEachlen[100];
    for(int i=1;i<=totallen;i++) cin>>priceofEachlen[i];
    usingbottomup(priceofEachlen,totallen);
    cout<<dp[totallen];
}
