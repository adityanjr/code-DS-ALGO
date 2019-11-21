#include <iostream>
using namespace std;

int main(){

    int numCases; scanf("%d\n",&numCases);
    const int numChars= 256;

    string J = "", S = "";
    int output = 0;

    while(numCases--){
        getline(cin, J); getline(cin, S);
        bool *present = new bool[numChars];
        output = 0;

        for(int k = 0; k < numChars; k++){present[k] = 0;}
        for(int k = 0; k < J.size(); k++){present[J[k]] = 1;}
        for(int k = 0; k < S.size(); k++){output += present[S[k]];}

        printf("%d\n",output);
    }

    return 0;
}
