#include <iostream>
using namespace std;

int main(){
    int n; cin>>n;

    int cumulative = 0;
    int recieved = 5;
    for(int i=1; i<=n; i++){
        int liked = recieved/2;
        int shared = liked*3;
        cumulative += liked;
        recieved = shared;
    }
    cout<<cumulative;
    return 0;
}