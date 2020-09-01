/*
   
   This problem was asked by Facebook.

   Given a function that generates perfectly random numbers between 1 and k (inclusive), 
   where k is an input, write a function that shuffles a deck of cards represented as an array using only swaps.

   It should run in O(N) time.

   Hint: Make sure each one of the 52! permutations of the deck is equally likely.

 */
#include <bits/stdc++.h>
using namespace std;
int main(void){
    srand(time(NULL));
    
    vector<int> v = {1 , 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    for(int i=0;i<(int)v.size()-1;++i){
        int new_position = rand()%(v.size()-i-1);
        swap(v[i] , v[new_position]);
    }

    for(auto&itr:v){
        cout<<itr<<' ';
    }
    cout<<'\n';

    return 0;
}
