#include <iostream>
using namespace std;
int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int steps = 0;
    int i=0;
    while(i<n-1){  //check upto second last
        if(arr[i+2]!=1){
            steps++;
            i+=2;
        }
        else {
            steps++;
            i++;
        }
    }
    cout<<steps;
}