#include<bits/stdc++.h>
using namespace std;

int dp[100001];
int arr[100001];

void solve(int n){
    for(int i=1;i<=n;i++) dp[i]=1;
    for(int i=n-1;i>=1;--i){
        if((arr[i]>0 && arr[i-1]>0 )||(arr[i]<0 && arr[i-1]<0)){
               dp[i]=1;
        }
        else{
            dp[i]= 1 + dp[i+1];
          }
        }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++) cin>>arr[i];
        solve(n);
        for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
        cout<<endl;
        memset(dp,0,sizeof(dp));
        memset(arr,0,sizeof(arr));
    }
    return 0;
}
