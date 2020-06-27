/*
 * This problem was asked by Snapchat.

    Given an array of time intervals (start, end) for classroom lectures 
    (possibly overlapping), find the minimum number of rooms required.

    For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int,int>a,pair<int,int>b){
    return a.first<b.first;
}
int main(void){
    vector<pair<int,int>>v;
    v.push_back({30,75});
    v.push_back({0,50});
    v.push_back({60,150});
    sort(v.begin(),v.end(),compare);
    int counter{},max_end_time=-1;//initially it is -1
    for(auto&[start_time,end_time]:v){
        if(max_end_time==-1){
            max_end_time=end_time;
            counter=1;
        }else{
            if(max_end_time>start_time){
                counter++;
            }else{
                max_end_time=end_time;
            }
        }
    }
    cout<<counter<<endl;
    return 0;
}
