#include <bits/stdc++.h>
using namespace std;
vector<int>ans;
bool get_sum(int k , vector<int>&arr , int current_index){
    if(current_index>(int)arr.size()){
        return false;
    }
    if(k==0){
        return true;
    }
    if(k<0){
        return false;
    }
    if(get_sum(k-arr[current_index],arr,current_index+1)){
        ans.push_back(arr[current_index]);
        return true;
    }else {
        return get_sum(k,arr,current_index+1);
    }
}
int main(int argc , char *argv[]){
    // write you code here
    int k = 24;
    vector<int>arr{12 , 1 , 61  , 5 ,  9 , 2};
    ans.clear();
    if(get_sum(k , arr , 0)){
        for(auto&itr:ans){
            cout<<itr<<' ';
        }
        cout<<'\n';
    }
    arr.clear();
    k = 13;
    arr = {12,9,2,1};
    ans.clear();
    if(get_sum(k , arr , 0)){
        for(auto&itr:ans){
            cout<<itr<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
