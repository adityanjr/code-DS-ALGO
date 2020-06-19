/*
 * This problem was asked by Stripe.  Given an array of integers, 
 * find the first missing positive integer in linear time and constant space. 
 *
 * In other words, find the lowest positive integer that does not exist in the array. 
 * The array can contain duplicates and negative numbers as well.  
 *
 * For example, the input [3, 4, -1, 1] should give 2. 
 *
 * The input [1, 2, 0] should give 3.  
 *
 * You can modify the input array in-place.
 *
 */
/*
 * 1. We can do simply with N^2 time complexity just search for each element form 1 
 *
 * 2. We can use un_ordered map & can do it in O(n) but it require extra O(n) space 
 *
 * 3. if array doesn't contain duplicate and negative number then we can use formula n*(n+1)/2 and
 *     subtract those number present in the array at last we will remain with the lowest number not 
 *     present in the array 
 *
 * 4. now let's separate the negative and positive element and then mark the index at element as -ve 
 *      now the first +ve index is our answer 
 *
 */
#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n; 
    cin>>n;
    vector<int>v(n);
    for(auto &itr:v){
        cin>>itr;
        itr--;
    }
    auto itr = partition(v.begin() , v.end() , [](int a){return a>=0;});
    for(auto i = v.begin(); i!=itr; ++i){
        if(*i>=v.size())
            continue;
        v.at(*i) = -v.at(*i);
    }
    int counter = 0;
    for(auto i = v.begin();counter<(int)v.size()&&i!=itr; ++i){
        if(v.at(counter)>0){
            cout<<counter+1<<endl;
            return 0;
        }
        counter++;
    }
    cout<<counter+1<<endl;
    return 0;
}

