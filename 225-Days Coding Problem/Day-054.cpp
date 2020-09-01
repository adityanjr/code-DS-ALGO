/*
   This problem was asked by Dropbox.

   Sudoku is a puzzle where you're given a partially-filled 9 by 9 grid with digits. The objective is to fill the grid with the constraint that every row, column, and box (3 by 3 subgrid) must contain all of the digits from 1 to 9.

   Implement an efficient sudoku solver.


input: :)
    
3 0 6 5 0 8 4 0 0  
5 2 0 0 0 0 0 0 0  
0 8 7 0 0 0 0 3 1  
0 0 3 0 1 0 0 8 0  
9 0 0 8 6 3 0 0 5  
0 5 0 0 9 0 6 0 0  
1 3 0 0 0 0 2 5 0  
0 0 0 0 0 0 0 7 4  
0 0 5 2 0 6 3 0 0  



output: 

3 1 6 5 7 8 4 9 2 
5 2 9 1 3 4 7 6 8 
4 8 7 6 2 9 5 3 1 
2 6 3 4 1 5 9 8 7 
9 7 4 8 6 3 1 2 5 
8 5 1 7 9 2 6 4 3 
1 3 8 9 4 7 2 5 6 
6 9 2 3 5 1 8 7 4 
7 4 5 2 8 6 3 1 9 


 */
#include <bits/stdc++.h>
using namespace std;
int grid[9][9];
pair<int,int> getFreeBox( void ) {
    for(auto i = 0; i< 9; ++i){
        for(auto j=0; j<9; ++j){
            if(grid[i][j] == 0){
                return make_pair(i,j);
            }
        }
    }
    return make_pair(-1 , -1);
}
bool isToPlace(pair<int,int>&p , int k){
    // is row safe
    int row= p.first;
    int col = p.second;
    for(int i=0;i<9; ++i){
        if(grid[row][i] == k){
            return false;
        }
    }
    for(int i=0;i<9; ++i){
        if(grid[i][col]==k){
            return false;
        }
    }
    // is box safe 
    int x = row - (row % 3);
    int y = col - (col % 3);
    for(auto i = 0; i<3; ++i){
        for(auto j=0; j<3; ++j){
            if(grid[i+x][j+y] == k){
                return false;
            }
        }
    }
    return true;
}
bool sol(void){
    pair<int,int>p = getFreeBox();
    if(p.first == -1 ){
        return true;
    }
    for(int i=1; i<=9; ++i){
        if(isToPlace(p , i)){
            grid[p.first][p.second] = i;
            if(sol()){
                return true;
            }
            grid[p.first][p.second] = 0;
        }
    }
    return false;
}
int main(void){
    freopen("input" , "r" , stdin);
    for(auto i = 0; i<9; ++i){
        for(auto j = 0; j<9; ++j){
            cin>>grid[i][j];
        }
    }
    if(sol()){
        for(auto i = 0; i<9; ++i){
            for(auto j = 0; j<9; ++j){
                cout<<grid[i][j]<<' ';
            }
            cout<<'\n';
        }
    }else{
        cout<<"No Solution"<<'\n';
    }
    return 0;
}
