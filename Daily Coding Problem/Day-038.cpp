/*
 *  This problem was asked by Microsoft.

    You have an N by N board.
    Write a function that, given N, returns the number of possible arrangements of the board
    where N queens can be placed on the board without threatening each other,
    
    i.e. no two queens share the same row, column, or diagonal.


 */
#include <bits/stdc++.h>
using namespace std;
bitset<40>column , d1 , d2; // d1 -> diagonal 1 & d2 -> diagonal 2
int NQueen(int n , int current){
    if(current == n){
        return 1;
    }

    int ways{};

    for(int i=0; i<n; ++i){
        if(!d1[i+current] && !d2[i-current+n-1] && !column[i]){
            d1[i+current] = d2[i-current+n-1] = column[i] = true;
            ways+=NQueen(n , current+1);
            d1[i+current] = d2[i-current+n-1] = column[i] = false;
        }
    }

    return ways;
}
int main(int argc , char *argv[]){
    // write you code here
    column.reset();
    d1.reset();
    d2.reset();
    int n; 
    cin>>n;
    cout << NQueen(n , 0) << '\n';
    return 0;
}
