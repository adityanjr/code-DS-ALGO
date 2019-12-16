#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int k,b;
int Boards[11];

int fn(int time){

    int painters_required = 1;
    int painterTime = 0;
    for(int i=0;i<b;i++){
        if(Boards[i]>time)
          return 0;
        painterTime += Boards[i];
        if(painterTime>time){
            painters_required++;
            painterTime = 0;
            i=i-1;
        }
    }

    if(painters_required>k)
        return 0;
    else
       return 1;
}

void binarysearch(ll l, ll r ){
    while(l<=r){
        ll mid = l + (r-l)/2;
        if(fn(mid)){
            r = mid-1;
        }
        else
           l = mid + 1;
    }
    cout<<r+1;
}

int main() {

    cin>>k>>b;
    ll sumOfBoards=0;
    for(int i=0;i<b;i++){
        cin>>Boards[i];
        sumOfBoards +=Boards[i];
    }
    binarysearch(0,sumOfBoards);
	return 0;
}
