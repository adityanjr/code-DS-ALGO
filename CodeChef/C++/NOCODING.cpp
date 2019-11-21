#include <iostream>
using namespace std;

int main(){

    int numCases; scanf("%d\n",&numCases);
    string message = "";
    const int mult = 11;
    const int numLetters = 26;
    int length = 0, count = 0, diff = 0;

    while(numCases--){
        getline(cin, message);
        length = message.size();
        count = 2;
        for(int k =1 ; k < length; k++){
            diff = message[k] - message[k-1];
            if(diff < 0){diff += numLetters;}
            count += 1 + diff; 
        }
        if(count <= length * mult){printf("YES\n");} else{printf("NO\n");}
    }
    return 0;
}
