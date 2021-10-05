#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[6][6];
    for (int i=0; i<6; i++) {
        for (int j=0; j<6; j++) {
            cin>>arr[i][j];
        }
    }
    int res = INT_MIN;

    for(int i=0; i<=3; i++){
        for(int j=0; j<=3; j++){
            int sum = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+
            arr[i+2][j+1]+arr[i+2][j+2];
            res = max(res,sum);
        }
    }
    cout<<res;

    return 0;
}
