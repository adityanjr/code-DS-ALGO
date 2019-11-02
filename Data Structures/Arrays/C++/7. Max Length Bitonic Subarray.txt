#include<iostream>
using namespace std;
int bitonic(int *A, int n) 
{ 
    if (n == 0) 
        return 0; 
          
    int maxLen=1; 
    int start=0; 
    int nextStart=0; 
          
    int j =0; 
    while (j < n-1) 
    {  
        while (j<n-1 && A[j]<=A[j+1]) 
            j++; 
              
        while (j<n-1 && A[j]>=A[j+1]){ 
            if (j<n-1 && A[j]>A[j+1]) 
                nextStart=j+1; 
            j++; 
        } 
        maxLen = max(maxLen,j-(start-1));
        start=nextStart; 
    } 
          
    return maxLen; 
} 
int main() {
  int t,n;
  cin>>t;
  int arr[1000];
  while(t--){
    cin>>n;
    for(int i=0;i<n;i++){
       cin>>arr[i];
    }
    cout<<bitonic(arr,n)<<endl;
  }
  return 0;
}
