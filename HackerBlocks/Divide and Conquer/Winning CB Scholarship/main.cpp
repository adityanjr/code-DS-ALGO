#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll N,M,X,Y;

int fn(int students){
    ll students_remaining  = N-students;
    return  students <= (M/X) + (Y*students_remaining)/X;
}
void binarysearch(ll l, ll r){
    while(l<=r){

        ll mid = l + (r-l)/2;
        if(fn(mid)){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout<<l-1<<endl;
}
int main() {


    cin>>N>>M>>X>>Y;

    if(M/X==N)
    {
        cout<<N<<endl;
        return 0;
    }

    binarysearch(M/X,N);

    return 0;
}
