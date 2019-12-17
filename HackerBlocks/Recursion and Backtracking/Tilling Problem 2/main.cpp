#include<bits/stdc++.h>
using namespace std;
int noOfWays = 0;
int tilling(int n, int m){
    // Base case
    if(n<0 || m<0){
        return 0;
    }
    if(n==0 || m==0){
        return 1;
    }

    return tilling(n-m,m-1) + tilling(n-1,0);

}
int main() {
	int n,m,t;
    cin>>t;
    while(t--){
    cin>>n>>m;
    cout<<tilling(n,m)<<endl;
    }
}
