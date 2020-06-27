/*
 *  This problem was asked by Google.

    You are given an M by N matrix consisting of booleans that represents a board. 
    Each True boolean represents a wall. Each False boolean represents a tile you can walk on.

    Given this matrix, a start coordinate, and an end coordinate,
    return the minimum number of steps required to reach the end coordinate from the start. 
    If there is no possible path, then return null. 
    You can move up, left, down, and right. 
    You cannot move through walls. You cannot wrap around the edges of the board.

    For example, given the following board:

    [[f, f, f, f],
    [t, t, f, t],
    [f, f, f, f],
    [f, f, f, f]]
    and start = (3, 0) (bottom left) and end = (0, 0) (top left), 
    the minimum number of steps required to reach the end is 7, 
    since we would need to go through (1, 2) because there is a wall everywhere else on the second row.
 *
 */


/* 
 * seems something NP-problem , Below is DP solution , 
 *
 * So idea is to visited every node and keep updating the distance to reach current Node (minimizing) 
 * if we found the already reaching distance is less then current distance then we will simply return because
 * there is some another path which will cause less cost to us. 
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
array<array<int,10>,10>dist;
void preprocess(pair<int,int>current_Point,bool matrix[4][4] , int current_Steps=-1){
    if(current_Steps>dist[current_Point.first][current_Point.second]){
        return;
    }
    dist[current_Point.first][current_Point.second] = min(dist[current_Point.first][current_Point.second],current_Steps+1);
    if(current_Point.first+1<4 && matrix[current_Point.first+1][current_Point.second]==false){
        preprocess(make_pair(current_Point.first+1,current_Point.second),matrix,current_Steps+1);
    }
    if(current_Point.second+1<4 && matrix[current_Point.first][current_Point.second+1]==false){
        preprocess(make_pair(current_Point.first,current_Point.second+1),matrix,current_Steps+1);
    }
    if(current_Point.first-1>=0 && matrix[current_Point.first-1][current_Point.second]==false){
        preprocess(make_pair(current_Point.first-1,current_Point.second),matrix,current_Steps+1);
    }
    if(current_Point.second-1>=0 && matrix[current_Point.first][current_Point.second-1]==false){
        preprocess(make_pair(current_Point.first,current_Point.second-1),matrix,current_Steps+1);
    }
    return;
}
int main(void){
    for(int i=0;i<10;++i){
        for(int j=0;j<10;++j){
            dist[i][j] = INT_MAX; // set maximum price initially 
        }
    }
    bool matrix[4][4]={
        {false , false , false , false},
        {true , true , false , true }, 
        {false , false , false , false},
        {false , false , false , false}
    };
    pair<int,int>start_Point , end_Point; 
    cin>>start_Point.first>>start_Point.second; //
    cin>>end_Point.first>>end_Point.second; //
    dist[start_Point.first][start_Point.second]=0;
    preprocess(start_Point,matrix);
    cout<<dist[end_Point.first][end_Point.second]<<endl;
    return 0;
}
