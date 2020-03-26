#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int arr[61];
long long int dp[61][10001];
int ans = 0;
int n;
ll solve(int pos,int gcd){

    if(pos==n){
        if(gcd==1)
            return 1;
        else
            return 0;
        }
    if(dp[pos][gcd]!=-1)
        return dp[pos][gcd];

    dp[pos][gcd] = solve(pos+1,gcd) + solve(pos+1,__gcd(gcd,arr[pos]));
    return dp[pos][gcd];
}
int main() {

    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++) cin>>arr[i];
        memset(dp,-1,sizeof(dp));
        long long int res = 0;

        for(int i=0;i<n;i++)
           res += solve(i+1,arr[i]);

        cout<<res<<endl;

    }
}
