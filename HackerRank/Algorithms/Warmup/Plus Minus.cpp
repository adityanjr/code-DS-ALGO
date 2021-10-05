#include <iostream>
using namespace std;

int main(){
    double pos=0, neg=0, zero=0;
    int n; cin>>n;
    int* arr = new int [n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n; i++){
        if(arr[i]>0){
            pos++;
        }
    }
    for(int i=0; i<n; i++){
        if(arr[i]<0){
            neg++;
        }
    }
    for(int i=0; i<n; i++){
        if(arr[i]==0){
            zero++;
        }
    }
    double posAns = pos/(double) n;
    double negAns = neg/(double) n;
    double zeroAns = zero/(double) n;

    printf("%.6lf\n", posAns);
    printf("%.6lf\n", negAns);
    printf("%.6lf\n", zeroAns);
}