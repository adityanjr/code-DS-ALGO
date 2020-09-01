/*
 *  This problem was asked by Dropbox.

 Conway's Game of Life takes place on an infinite two-dimensional board of square cells. 

 Each cell is either dead or alive, and at each tick, the following rules apply:

 Any live cell with less than two live neighbours dies.
 Any live cell with two or three live neighbours remains living.
 Any live cell with more than three live neighbours dies.
 Any dead cell with exactly three live neighbours becomes a live cell.
 A cell neighbours another cell if it is horizontally, vertically, or diagonally adjacent.

 Implement Conway's Game of Life. It should be able to be initialized with a starting list of live cell coordinates and the number of steps it should run for. Once initialized, it should print out the board state at each step. Since it's an infinite board, print out only the relevant coordinates, i.e. from the top-leftmost live cell to bottom-rightmost live cell.

 You can represent a live cell with an asterisk (*) and a dead cell with a dot (.).
 */

#include <bits/stdc++.h>
using namespace std;
vector< pair< int , int >>direction{{0,-1} , {-1 , 0} , {-1 , -1} , {1 , -1} , {0 , 1} , {-1 , 1} , {1 , 0} , {1 , 1}};
int main(int argc , char *argv[]){
    // write you code here
    int row , col;
    cin >> row >> col;
    vector<vector<int>>grid(row,vector<int>(col,1));
    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            cin>>grid[i][j];
        }
    }
    while(1){
        /*
         *  1 -> current cell is active 
         *  2 -> current cell was dead but now active
         *  0 -> current cell is dead
         *  -1-> current cell was active but now dead
         */

        auto valid = [row , col](int x, int y){
            return x>=0 && y>=0 && x<row && y<col;
        };

        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                int live_neighbour{};
                for(auto &[x ,y]:direction){
                    if(valid(i+x , y+j)){
                        live_neighbour+=(abs(grid[i+x][j+y]) ==1);
                    }
                }
                
                if(grid[i][j]==1 && (live_neighbour < 2 || live_neighbour >3)){
                    grid[i][j] = -1;
                }

                if(grid[i][j]==0 && (live_neighbour == 3)){
                    grid[i][j] = 2;
                }
            }
        }

        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(grid[i][j]>0){
                    cout<<"* ";
                    grid[i][j] = 1;
                }else{
                    cout<<". ";
                    grid[i][j] = 0;
                }
            }
            cout<<'\n'; 
        }
        cin.ignore();
        char close; 
        cin >> close;
        if(close == 'y' || close == 'Y'){
            break;
        }
    }
    return 0;
}
