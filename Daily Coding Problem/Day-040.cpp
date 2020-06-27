/*
  This problem was asked by Google.

  Given an array of integers where every integer occurs three times except for one integer,
  which only occurs once, find and return the non-duplicated integer.

  For example, given [6, 1, 3, 3, 3, 6, 6], return 1. Given [13, 19, 13, 13], return 19.

  Do this in O(N) time and O(1) space.
 */
#include <bits/stdc++.h>
using namespace std;
int main(int argc , char *argv[]){
    // write you code here
    vector< int > array_1 { 6, 1, 3, 3, 3, 6, 6 };
    vector< int > array_2 { 13, 19, 13, 13 };
    vector< int > bit(30, 0); // if values goes higher then take a largest bit - array
    for(auto&itr: array_1){
        for(int i=0; i < 30; ++i){
            if(itr&(1<<i)){
                bit.at(i)++;
            }
        }
    }
    int ans{};
    for(int i=0; i<30; ++i){
        ans += ((bit.at(i)%3)<<i);
    }
    cout << ans << '\n';


    /// for array 2 

    fill_n(begin(bit) , 30 , 0);
    for(auto&itr: array_2){
        for(int i=0; i < 30; ++i){
            if(itr&(1<<i)){
                bit.at(i)++;
            }
        }
    }
    ans = 0;

    for(int i=0; i<30; ++i){
        ans += ((bit.at(i)%3)<<i);
    }

    cout << ans << '\n';
    return 0;
}
