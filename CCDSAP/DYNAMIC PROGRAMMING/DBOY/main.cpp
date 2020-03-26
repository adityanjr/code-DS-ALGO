#include <bits/stdc++.h>
using namespace std;
#define ll int

int main()
{
     ll t;
     cin>>t;
     while(t--){
        ll n;
        cin>>n;
        ll H[501];
        ll K[501];
        ll max_ele = INT_MIN;
        for(int i=0;i<n;i++) {
            cin>>H[i];
            max_ele =max(max_ele,H[i]);
        }
        max_ele = 2* max_ele;
        for(int i=0;i<n;i++ ){
            cin>>K[i];
        }
        ll dp[max_ele+1];
        for(int i=1;i<=max_ele;i++){
           dp[i] = INT_MAX;
        }

        dp[0]=0;
        for(int i=1;i<=max_ele;i++){
            for(int j=0;j<n;j++){
                if(i-K[j]>=0 && dp[i-K[j]]!=INT_MAX)
                    dp[i] = min(dp[i],1+dp[i-K[j]]);
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++) {
            ans += dp[2*H[i]];
        }
        cout<<ans<<endl;
     }
     return 0;
}
