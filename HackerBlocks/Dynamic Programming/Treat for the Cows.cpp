#include <bits/stdc++.h>
using namespace std;
int memo[2000][2000];
int dp[2000][2000];
int arr[2000];

// Using bottom-up approach
/* 1. Because at any given point of time we need to know three things
       -> Start
       -> End
       -> Year
    Reflecting that our dp array should 3D. If we oberserve a little more we can see that we can compute year using just start, end and size of the array. 
    Now, our dp array should be 2D and we have managed to overcome a significant overhead. 
    
   2. At any given point of time lets say (i,j) in 2D array denotes the maximum possible value we can obtain when we have arr[i...j] wines left with us.
   3. If i>j then we have to ignore these indices because we cannot have conditions where start is bigger than ending.
*/

void solveusingbottomup(int s, int e, int year){
    
    for(int i=s;i<=e;i++){
        dp[i][i] = year * arr[i];
    }
    year--;
    for(int i=1;i<=e;i++){
        int start = 0;
        int end =  e - i;
        while(start<end){
            int j = start + i;
            int q1 = arr[start]*year + dp[start+1][j];
            int q2 = arr[j]*year + dp[start][j-1];
            dp[start][j] = max(q1,q2);
            start++;
         }
         year--;
    }
}
// Using Memoization, It is just like recursion, but instead of ignoring the computed value we will store it in an array.
// Since we have "s" and "e" as the states. we will declare a 2d array.
// This will get accepted.
int solveusingmemoization(int arr[], int s, int e, int year){
    if(s>e)
      return 0;
    
    if(memo[s][e]!=-1) return memo[s][e];
   
     int q1 = arr[s]*year + solveusingmemoization(arr,s+1,e,year+1);
     int q2 = arr[e]*year + solveusingmemoization(arr,s,e-1,year+1);
     memo[s][e]  = max(q1,q2);
     return memo[s][e];
}


/* Recursive Solution which is not efficient. 
int solveusingrecursion(int arr[], int s, int e, int year){
        if(s>e){
            return 0;
        }

        int q1 = arr[s]*year + solveusingrecursion(arr,s+1,e,year+1);
        int q2 = arr[e]*year + solveusingrecursion(arr,s,e-1,year+1);
        return max(q1,q2);
}   */

int main() {
     int n;
     cin>>n;
     for(int i=0;i<n;i++) cin>>arr[i];
     memset(memo,-1,sizeof(memo));
     solveusingbottomup(0,n-1,n);
     cout<<dp[0][n-1];
}
