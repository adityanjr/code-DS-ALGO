#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int arr[100];
ll dp[100][100];

ll sum(int s,int e){
    ll ans = 0;
    for(int i=s;i<=e;i++){
        ans = (ans + arr[i])%100;
    }
    return ans;
}

ll solveMinimum(int i, int j){

    if(i>=j)
      return 0;

    if(dp[i][j]!=-1)
      return dp[i][j];

    dp[i][j] = INT_MAX;

    for(int k=i;k<=j;k++){
        dp[i][j]= min(dp[i][j],solveMinimum(i,k)+solveMinimum(k+1,j)+(sum(i,k)*sum(k+1,j)));
    }

    return dp[i][j];
}


int main() {
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++)
        cin>>arr[i];

        for(int i=0;i<100;i++)
            for(int j=0;j<100;j++){
                dp[i][j]=-1;
            }
    cout<<solveMinimum(0,n)<<endl;
    }
}
