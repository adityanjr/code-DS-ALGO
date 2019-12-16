#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll m,n;
ll books[100005];
ll start  = INT_MIN;
ll sum = 0;

int fn(int pages){
    int students = 1;
    int sumofstudents = 0;
    for(int i=0;i<n;i++){

       if(sumofstudents+books[i]>pages){
          sumofstudents = books[i];
          students++;
          if(students>m)
            return 0;
       }
       else{
           sumofstudents += books[i];
       }
    }
    return 1;
}
void binarysearch(ll l, ll r){
    while(l<=r){
        ll mid = l+(r-l)/2;

        if(fn(mid)){
            r = mid -1;
        }

        else {
            l = mid + 1;
        }
    }
     cout<<r+1;
}
int main(){

    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>books[i];
        sum+=books[i];
        start = max(start,books[i]);
    }

    binarysearch(start,sum);
    return 0;
}
