/*
   This problem was asked by Facebook.

   You are given an array of non-negative integers that represents a two-dimensional
   elevation map where each element is unit-width wall and the integer is the height.

   Suppose it will rain and all spots between two walls get filled up.

   Compute how many units of water remain trapped on the map in O(N) time and O(1)
   space.

   For example, given the input [2, 1, 2], we can hold 1 unit of water in the middle.

   Given the input [3, 0, 1, 3, 0, 5], we can hold 3 units in the first index, 2 in
   the second, and 3 in the fourth index (we cannot hold 5 since it would run off
   to the left), so we can trap 8 units of water.
*/

/*
 *  As we need O(N) time  and O(1) space so we are not going to use Stack OR precomputed array solution
 *  we will stick to sliding window algorithm that will do it in O(1) space & O(N) time
 */

#include <bits/stdc++.h>

using namespace std;

int main(void){
    int size_of_array; 
    cin >> size_of_array;
    
    vector< int > height_array ( size_of_array );

    for(auto &height : height_array){
        cin >> height;
    }
    
    int max_level{} , left = 0 , right = size_of_array - 1 , ans{};

    while(left < right){

        int lower_height = height_array.at( height_array.at(left) < height_array.at(right) ? left++ : right-- ); // take the lower 

        max_level = max( max_level , lower_height ); // max-level/height we have seen so far 

        ans += (max_level - lower_height);
    }

    cout << ans << '\n' ;

    return 0;
}
