#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n; cin>>n;
    int** arr = new int*[n];
    for(int i = 0; i < n; ++i)
        arr[i] = new int[n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
                cin>>arr[i][j];
        }
    }
    int leftSum =0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j){
                leftSum += arr[i][j];
            }
        }
    }
    int rightSum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==n-j-1){
                rightSum += arr[i][j];
            }
        }
    }
    cout<<abs(leftSum-rightSum);
}