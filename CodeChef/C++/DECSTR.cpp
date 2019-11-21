#include <iostream>
using namespace std;

int main(){

    const int numLetters = 26;
    int cases; scanf("%d",&cases);
    int positions, length;

    while(cases--){
        scanf("%d",&positions);
        string msg = "",output = "";
        length = positions + 1 + (positions-1)/(numLetters-1);
        for(int k = 0; k < length ; k++){msg += 'a'+ k % numLetters;}
        for(int k = 0; k < length ; k++){output += msg[length - k - 1];}
        cout << output << endl;
    }
    return 0;
}
