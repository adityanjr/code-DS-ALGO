#include <iostream>
#include<string>
using namespace std;

int editDistance(string out, string inp){
    int dp[101][101];
    int n = inp.length();
    int m = out.length();

    for(int i=0;i<=m;i++)
          dp[0][i] = i;
    
    for(int i=0;i<=n;i++)
    {
        dp[i][0] = i;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
             int q1 = dp[i][j-1] ; // Insertion
             int q2 = dp[i-1][j]; // Deletion
             int q3 = dp[i-1][j-1]; // Replacement
             dp[i][j] = min(q1,min(q2,q3)) + (inp[i-1]!=out[j-1]);
         }
    }
    return dp[n][m];
}
int main() {
      string input,output;
      cin>>input>>output;
      cout<<editDistance(output,input);

}
