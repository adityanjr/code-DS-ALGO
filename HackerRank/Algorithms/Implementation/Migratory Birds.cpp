#include <iostream>
using namespace std;

int main(){

    int n; cin>>n;
    int arr[n];
    int count[6]={0};
    int type, ans, max=0;

    for(int i=0; i<n; i++){
        cin>>type;
        count[type]++;

        if(count[type] == max && type<ans){
            ans = type;
        }
        if(count[type] > max){
            ans = type;
            max = count[type];
        }
    }
    cout<<ans;

}