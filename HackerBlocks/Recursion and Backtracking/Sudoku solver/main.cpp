#include <bits/stdc++.h>
using namespace std;
bool canPlace(int sudoku[][9],int i, int j, int n, int num){

    for(int k=0;k<n;k++){
        if(sudoku[i][k]==num)
          return false;
    }

    for(int k=0;k<n;k++){
        if(sudoku[k][j]==num)
         return false;
    }

    int ss = sqrt(n);
    int x = (i/ss)*ss;
    int y = (j/ss)*ss;

    for(int sx = x ; sx< x+ss; sx++){
        for(int sy = y; sy<y+ss; sy++){
            if(sudoku[sx][sy]==num)
                return false;
        }
    }
    return true;
}

bool solvesudoku(int sudoku[][9],int i, int j, int n){
    if(i==9){
        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                cout<<sudoku[x][y]<<" ";
            }
            cout<<endl;
        }
        return true;
    }

    if(j==9)
       return solvesudoku(sudoku,i+1,0,n);

    if(sudoku[i][j]!=0)
       return solvesudoku(sudoku,i,j+1,n);
    for(int k=1;k<=n;k++){
            if(canPlace(sudoku,i,j,n,k)){
                 sudoku[i][j]=k;
                 bool sucess = solvesudoku(sudoku,i,j+1,n);
                 if(sucess){
                    return true;
                  }
               }
          }

    sudoku[i][j]=0;
    return false;
}
int main() {
    int n;
    cin>>n;
    int sudoku[9][9];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>sudoku[i][j];
        }
    }
    solvesudoku(sudoku,0,0,n);
}
