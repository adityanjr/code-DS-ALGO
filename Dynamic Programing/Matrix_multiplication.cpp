#include<bits/stdc++.h>

using namespace std;

 int matrixMultiplication(int N, int arr[])
    {
        // code here
        //N-1 matrix are there
        int dp[N-1][N-1];
        
        memset(dp,0,sizeof(dp));
        
        
        for(int gap = 0; gap<N-1 ; gap++){
            for(int i=0,j=gap ; j<N-1 ;j++,i++){
                
                
                if(gap==0){
                    dp[i][j] = 0;
                }
                else if(gap==1){
                    dp[i][j] = arr[i]*arr[i+1]*arr[i+2];
                }
                
                
                else{
                    int ans = INT_MAX;
                    
                    for(int k=i;k<j;k++){
                    int left = dp[i][k];
                    int right = dp[k+1][j];
                    int val = arr[i]*arr[k+1]*arr[j+1];
                    
                    ans = min(ans, left+right+val);
                    }
                     dp[i][j] = ans;
                }
                
               
            }
        }
        return dp[0][N-2];
    }
    

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<matrixMultiplication(n,arr)<<endl;


    return 0;
}