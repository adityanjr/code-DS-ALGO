#include <iostream>
using namespace std;

int main() {
    int t; cin>>t;

    while(t--) {
        string str;
        cin >> str;

        for(int i=0; i<str.length(); i++){
            if(i%2 == 0) cout<<str[i];
        }
        cout << " ";

        for(int i=0; i<str.length(); i++){
            if(i%2 != 0) cout<<str[i];
        }
        cout << endl;
    }
    return 0;
}