#include <iostream>
using namespace std;

int main(){

    int numCases; scanf("%d\n",&numCases);
    const int numLetters= 26;
    const int ansModulo = 10000009;

    string recipe = "";
    int length = 0;
    size_t output = 0;
    char first = 'a', second = 'a';

    while(numCases--){
        getline(cin, recipe);
        length = recipe.size();
        output = 1;
        for(int index = 0; index < (length+1)/2 ; index++){
            first = recipe[index]; second = recipe[length - 1 - index];
            if(first == '?' && second == '?'){output *= numLetters; output %= ansModulo;}
            if(first != '?' && second != '?' && first != second){output = 0; break;}
        }
        printf("%zd\n",output);
    }

    return 0;
}
