#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int dp[1001][1001];

int solve(int M, int N){

    if(dp[0][0]==-1)
     return 0;

    if(dp[M-1][N-1]==-1)
      return 0;

    for(int i=0;i<M;i++){
        if(dp[i][0]==-1)
           break;
        dp[i][0] = 1;
    }

    for(int j=0;j<N;j++){
        if(dp[0][j]==-1)
          break;
        dp[0][j]=1;
    }

    for(int i=1;i<M;i++){
        for(int j=1;j<N;j++){
            if(dp[i][j]==-1)
             continue;

            dp[i][j] = 0;
            if(dp[i-1][j]!=-1){
                dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD;
            }

            if(dp[i][j-1]!=-1){
                dp[i][j] = (dp[i][j] + dp[i][j-1])%MOD;
            }
        }
    }

    return dp[M-1][N-1];
}
int main() {
   int M,N,P;
   cin>>M>>N>>P;
   int a,b;
   for(int i=0;i<P;i++){
       cin>>a>>b;
       dp[a-1][b-1]=-1;
   }
   cout<<solve(M,N);
}
