#include <bits/stdc++.h>
using namespace std;
int p,L;
int arr[51];
int ans;
int fn(int time){
    int totalparantha = 0;
    for(int i=0;i<L;i++){
        int val = arr[i];
        int time_taken = 0;
        int j = 1;
        while(true){
            time_taken += j*val;
            if(time_taken>time)
                break;
            else{
                totalparantha++;
                j++;
            }
            if(totalparantha==p)
                return 1;
        }
    }
    return 0;
}
void binarysearch(int l, int r){
    while(l<=r){
        int mid = l + (r-l)/2;

        if(fn(mid)){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout<<r+1;
}
int main()
{
    cin>>p>>L;
    int temp = INT_MAX;
    for(int i=0;i<L;i++){
        cin>>arr[i];
        temp = min(temp,arr[i]);
    }
    int summation = ((p*(p+1))/2)*temp;
    binarysearch(0,summation);
    return 0;
}
