/*

This problem was asked by Google.

A knight's tour is a sequence of moves by a knight on a chessboard such that all squares are visited once.

Given N, write a function to return the number of knight's tours on an N by N chessboard.



 My Testcase :

input : 1 , Output : 1
input : 2 , Output : 0 
input : 3 , Output : 0
input : 4 , Output : 0
input : 5 , Output : 1728 (it took 23 seconds) 

 */
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>jump{{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
vector<vector<bool>>grid;
bool valid(int x , int y , int n){
    if(x>n || y>n || x<1 || y<1){
        return false;
    }
    if(grid[x][y] == true )
        return false;
    return true;
}
long long count_ways(int x , int y , int n ,int move_number = 1){
    if(move_number == n*n){
        return 1;
    }
    int ways_counter{};
    if(x>n || y>n || x<1 || y<1){
        return ways_counter;
    }
    grid[x][y] = true;
    for(int k=0;k<(int)jump.size();++k){
        if(valid(x+jump.at(k).first , y+jump.at(k).second , n)){
            ways_counter+=count_ways(x+jump.at(k).first , y+jump.at(k).second , n , move_number+1 );
        }
    }
    grid[x][y] = false;
    return ways_counter;
}
int main(void){
    int n; cin>>n;
    grid.assign(n+1 , vector<bool>(n+1,false));
    long long counter{};
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            counter+=count_ways(i,j,n);
        }
    }
    cout<<counter<<'\n';
    return 0;
}
