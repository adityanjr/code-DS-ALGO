/*
 *  
    This problem was asked by Facebook.

    A builder is looking to build a row of N houses that can be of K different colors.
    He has a goal of minimizing cost while ensuring that no two neighboring houses are of the same color.

    Given an N by K matrix where the nth row and kth column represents the cost to build 
    the nth house with kth color, return the minimum cost which achieves this goal.

 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n , m; cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m,0));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>v[i][j];
        }
    }
    int k=m; // number of colors
    vector<vector<int>>dp(n+1,vector<int>(k,0));
    // dp[i][j] = cost of building ith house with jth color 
    for(int j=0;j<k;++j){
        dp[0][j] = v[0][j];
    }
    for(int i=1;i<n;++i){
        for(int j=0;j<k;++j){
            dp[i][j] = INT_MAX;
            for(int l=0;l<k;++l){
                if(j==l){
                    continue;
                }
                dp[i][j] = min(dp[i][j]  , dp[i-1][l]);
            }
            dp[i][j] += v[i][j];
        }
    }
    int ans{INT_MAX};
    for(int i=0;i<k;++i){
        ans = min(ans , dp[n-1][i]);
    }
    cout<<ans<<endl;
    return 0;
}
