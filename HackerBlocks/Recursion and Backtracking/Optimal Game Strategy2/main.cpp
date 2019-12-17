#include<bits/stdc++.h>
using namespace std;
int maxval = INT_MIN;
vector<vector<int>>val;

int  optimalGamestrategy(int arr[],int i, int j,int sum){

        if(j==i+1){
            return max(arr[i],arr[j]);
        }
        if(val[i][j]!=-1)
           return val[i][j];

       val[i][j] = max(sum- optimalGamestrategy(arr,i+1,j,sum-arr[i]),sum - optimalGamestrategy(arr,i,j-1,sum-arr[j]));
       return val[i][j];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    int sum = 0;
    val.resize(2000,vector<int>(2000,-1)); // Resize the vector to form [2000][2000] 2D array;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    cout<<optimalGamestrategy(arr,0,n-1,sum)<<endl;
}
