/*
 This problem was asked by Google.

 The power set of a set is the set of all its subsets. Write a function that, given a set, generates its power set.

 For example, given the set {1, 2, 3}, it should return {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.

 You may also use a list or array to represent a set. 
  
 */


/*
 * you could use vector < vector > and sort them in last to get a list of list 
 *
 */
#include <bits/stdc++.h>
using namespace std;
int main(int argc , char *argv[]){
    // write you code here
    vector< int > arr {1 , 2  , 3};
    int bit = (1 << (int)arr.size());
    for(int i{}; i < bit; ++i){
        vector< int > element;
        for(int j=0; j<(int)arr.size(); ++j){
            if(i&(1<<j)){
                element.push_back(arr[j]);
            }
        }
        printf("{ ");
        for(int j=0; j< (int)element.size(); ++j){
            cout << element.at(j) << ' ';
            if(j+1 !=(int) element.size()){
                printf(", ");
            }
        }
        printf("}");
        if(i+1 != bit){
            printf(", ");
        }
    }
    cout << '\n' ;
    return 0;
}

