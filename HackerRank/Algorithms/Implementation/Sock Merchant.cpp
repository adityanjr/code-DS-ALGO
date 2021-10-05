#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    int count = 0, i=0;
    while(i<n){
        if(arr[i] == arr[i+1]){
            count++;
            i+=2;
        }
        else {
            i++;
        }
    }
    cout<<count;
}

//Frequency array

#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int pairs[100];
    int count = 0;

    for (int i = 0; i < n; ++i) {
        int c; cin >> c;
        pairs[c-1] == c ? pairs[c-1] = !(count+=1) : pairs[c-1] = c;
    }

    cout << count << "\n";

    return 0;
}