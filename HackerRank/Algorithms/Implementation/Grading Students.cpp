#include <iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int* arr = new int[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n; i++){
        if(arr[i]<38){
            cout<<arr[i]<<endl;
        }
        else {
            int a = (arr[i]/5)*5;
            int b = a + 5;
            if(b-arr[i]<3){
                cout<<b<<endl;
            }
            else{
                cout<<arr[i]<<endl;
            }
        }
    }
}