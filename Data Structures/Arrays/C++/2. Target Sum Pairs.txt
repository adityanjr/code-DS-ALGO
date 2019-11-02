#include<iostream>
using namespace std;
int main() {
    int n;
    int arr[100];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++){ 
            if (arr[i] + arr[j] == target) {
                if( arr[i]> arr[j]){   // print answer in increasing order..
                    int x=arr[i];
                    arr[i]=arr[j];
                    cout << arr[i] << " and " << x << endl;
                }
            else {
               cout << arr[i] << " and " << arr[j] << endl;
            }   
            }
        }
    }    
	return 0;
}