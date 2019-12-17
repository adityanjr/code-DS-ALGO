#include <bits/stdc++.h>
using namespace std;
bool isvalid(int board[][10], int i, int j,int n){
    for(int k=0;k<=i;k++){
        if(board[k][j]==1)
          return false;
    }

    int x = i;
    int y = j;
    while(x>=0 && y>=0){
        if(board[x--][y--]==1)
          return false;
    }

     x = i;
     y = j;
    while(x>=0 && y<n){
        if(board[x--][y++]==1)
          return false;
    }
    return true;
}
bool nqueen(int board[][10],int i,int n){
    if(i==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1)
                    cout<<"Q ";
                else
                  cout<<"_ ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
        return false; // Make it true to get only one possible arrangement and remove the above line.
    }

      for(int j=0;j<n;j++){
        if(isvalid(board,i,j,n)){
            board[i][j]=1;
            bool valid = nqueen(board,i+1,n);
            if(valid){
               return true;
            }
            board[i][j]=0;
          }
       }
       return false;
}

int main(){
    int n;
    int board[10][10] = {0};
    cin>>n;
    nqueen(board,0,n);
    return 0;
}
