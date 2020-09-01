/*
    This problem was asked by Airbnb.

    Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. 

    Numbers can be 0 or negative.

    For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. 
    
    [5, 1, 1, 5] should return 10, since we pick 5 and 5.

    Follow-up: Can you do this in O(N) time and constant space?

*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    int number_of_element;
    cin>>number_of_element;
    vector<int>element(number_of_element);
    for(auto &itr:element){
        cin>>itr;
    }
    int including(0) , excluding(0); // consider these as state of dp . HOW ?
    // take including as max sum we get till now including this element 
    // take excluding as max sum we get till now excluding this element 
    //
    // initially both of them are 0. 
    //
    // so in next state what will be our including simple max(including , excluding+current_element)
    // 
    // what will be excluding ; simple the including we got till now because we excluded the current element 
    // and the max sum we achieved till now is the same as present in the including variable 
    //
    // but how take care of 0 and negative number ?????
    //
    // simple you can just ignore them they are not going to contribute to answer in any way ;)
    //

    for(int current_Index=0;current_Index<number_of_element;++current_Index){
        if(element.at(current_Index)<=0){
            excluding = including ;
        }
        if(current_Index==0){
            including = element.at(current_Index);
        }else{
            int temp = including;
            including = max(including , excluding + element.at(current_Index));
            excluding = temp; // we excluded the current element 
        }
    }
    cout<<including <<endl;
    return 0;
}
