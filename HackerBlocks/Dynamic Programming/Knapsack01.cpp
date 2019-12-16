#include <bits/stdc++.h>
using namespace std;


int knapSack(int W, int wt[], int val[], int n) 
{ 
   int i, w; 
   int K[n+1][W+1]; 
   memset(K,0,sizeof(K));

   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (wt[i-1] <= w) 
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 
   
   for(int i = 0;i<=n;i++){
       for(int j = 0;j<=W;j++){
           cout<<K[i][j]<<" ";
       }
       cout<<endl;
   }
   return K[n][W]; 
}

int main() {
    int N,S;
    cin>>N>>S;
    int wt[N];
    int Val[N];
    for(int i = 0;i<N;i++){
            cin>>wt[i];
    }
    for(int i = 0;i<N;i++){
        cin>>Val[i];
    }
    cout<<knapSack(S,wt,Val,N)<<endl;

}
