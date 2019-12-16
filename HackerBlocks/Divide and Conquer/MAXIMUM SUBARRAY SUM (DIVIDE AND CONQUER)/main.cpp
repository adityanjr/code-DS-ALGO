#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int maxtheSubarray(int arr[],int low, int high){
   if(low>=high)
       return arr[low];

   int mid = low + (high-low)/2;

   int maxLeft = INT_MIN;
   int sum = 0;
   for(int i=mid;i>=low;i--){
       sum += arr[i];
       maxLeft = max(maxLeft,sum);
   }

   sum  = 0;
   int maxRight = INT_MIN;
   for(int i=mid+1;i<=high;i++){
       sum+=arr[i];
       maxRight = max(sum,maxRight);
   }

   int maxInLeftOverarray = max(maxtheSubarray(arr,low,mid),maxtheSubarray(arr,mid+1,high));

   return max(maxInLeftOverarray,maxLeft + maxRight);
}
int main() {
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<maxtheSubarray(arr,0,n-1)<<endl;
        for(int i=0;i<n;i++)
          arr[i]=0;
    }
}
