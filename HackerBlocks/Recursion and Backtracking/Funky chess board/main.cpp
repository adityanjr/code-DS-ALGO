#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int board[10][10]={0};
bool isVisited[10][10] ={false};
int n;
int counter = INT_MAX;
// (r-2,c-1), (r-2,c+1), (r-1,c-2), (r-1,c+2), (r+1,c-2), (r+1,c+2), (r+2,c-1), or (r+2,c+1)
// backtracking is used.
bool isValid(int i, int j){

    return (i>=0) && (i<n) && (j<n) && (!isVisited[i][j]) && (j>=0) && (board[i][j]==1);
}

void solveKnight(int board[][10], int i, int j){
    isVisited[i][j]=true;
    if(!(isValid(i-2,j-1) || isValid(i-2,j+1) || isValid(i-1,j-2) || isValid(i-1,j+2) || isValid(i+1,j-2) || isValid(i+1,j+2) || isValid(i+2,j-1) || isValid(i+2,j+1))){
        int temp=0;
        for(int k=0;k<n;k++){
            for(int l=0;l<n;l++){
                if(board[k][l]==1 && isVisited[k][l]==false)
                    temp++;
            }
        }
        if(temp<counter)
            counter = temp;
        return;
    }

    if(isValid(i-2,j-1)){
        solveKnight(board,i-2,j-1);
        isVisited[i-2][j-1]= false;
    }

     if(isValid(i-2,j+1)){
        solveKnight(board,i-2,j+1);
        isVisited[i-2][j+1]= false;

    }
    if (isValid(i-1,j-2)){
        solveKnight(board,i-1,j-2);
       isVisited[i-1][j-2]= false;
    }
    if(isValid(i-1,j+2)){
        solveKnight(board,i-1,j+2);
          isVisited[i-1][j+2]= false;
    }
    if(isValid(i+1,j-2)){
        solveKnight(board,i+1,j-2);
            isVisited[i+1][j-2]= false;
    }
    if(isValid(i+1,j+2)){
        solveKnight(board,i+1,j+2);
       isVisited[i+1][j+2]= false;
    }
     if(isValid(i+2,j-1)){
        solveKnight(board,i+2,j-1);
               isVisited[i+2][j-1]= false;
    }
     if(isValid(i+2,j+1)){
        solveKnight(board,i+2,j+1);
        isVisited[i+2][j+1]= false;
    }

    return;

}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }
    solveKnight(board,0,0);
    cout<<counter<<endl;
    return 0;
}
