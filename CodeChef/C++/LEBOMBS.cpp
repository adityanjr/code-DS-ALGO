#include <iostream>
using namespace std;

int main(){
    
    string input, shiftLeft, shiftRight;
    int numCases; scanf("%d\n",&numCases);
    while(numCases--){
        int numBuildings; scanf("%d\n",&numBuildings);
        getline(cin, input);
        shiftLeft = input.substr(1,numBuildings-1)+'0';
        shiftRight = '0'+input.substr(0,numBuildings-1);
        size_t destroyed = 0;
        for(size_t k = 0; k < numBuildings; k++){if(input[k] == '1' || shiftLeft[k] == '1' || shiftRight[k] == '1'){destroyed++;}}
        printf("%zd\n",numBuildings - destroyed);
    }

    return 0;
}
