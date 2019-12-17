#include <bits/stdc++.h>
using namespace std;
int t;
int h;
int dp[20][20];
int temp_board[20][20]={0};

void makeZero(int board[20][20],int hll){

    for(int i=0;i<20;i++){
        for(int j=0;j<5;j++){
            dp[i][j] = -1e8;
        }
    }

      for(int i=0;i<20;i++){
         for(int j=0;j<5;j++){
            temp_board[i][j]=board[i][j];
          }
       }

    for(int i=hll;i<hll+5;i++){
        for(int j=0;j<5;j++){
            if(temp_board[i][j]==-1)
                temp_board[i][j]=0;
        }
    }
}

int makeitMax(int temp_board[][20], int i, int j){

    if(i==-1)
         return 0;

    if(dp[i][j]!=-1e8)
        return dp[i][j];

    int &ans = dp[i][j];

    ans = max(ans,temp_board[i][j]+makeitMax(temp_board,i-1,j));
    if(j<4)
      ans = max(ans,temp_board[i][j]+makeitMax(temp_board,i-1,j+1));
    if(j>0)
      ans = max(ans,temp_board[i][j]+makeitMax(temp_board,i-1,j-1));

    return ans;
}

int main()
{
    cin>>t;
    while(t--){
        int board[20][20]={0};
        cin>>h;
        for(int i=0;i<h;i++){
            for(int j=0;j<5;j++){
                cin>>board[i][j];
            }
        }
        int alltimeMax=-1e8;
        if(h<5){
              int max_value = makeitMax(board,h,2);
              alltimeMax = max(max_value,alltimeMax);
        }
        else {
            for(int hll= 0;hll<h-4;hll++){
                makeZero(board,hll);
                int je = makeitMax(temp_board,h,2);
                alltimeMax = max(alltimeMax,je);
            }
      }
       cout<<alltimeMax<<endl;
    }
    return 0;
}
