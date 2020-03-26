#include <bits/stdc++.h>
using namespace std;
int main()
{   ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char arr[n+1][n+1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>arr[i][j];
            }
        }
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++){
            dp[0][i] = 0;
            dp[i][0] = 0;
        }

        for(int i=1;i<=n;i++){
            int blocked = 1;
            for(int j=n;j>=1;j--){
                if(arr[j][i]=='.'){
                    dp[j][i] = blocked + dp[j][i-1];
                }
                else{
                    blocked = 0;
                    dp[j][i] = 0;
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            ans += dp[i][n];
        }
        cout<<ans<<endl;
    }
    return 0;
}
