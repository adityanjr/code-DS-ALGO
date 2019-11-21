#include <iostream>
using namespace std;

bool checkSubsequence(string first, string second){

    size_t sizeFirst = first.size(), sizeSecond = second.size(), index = 0;
    if(sizeFirst > sizeSecond){return 0;}
    for(size_t k = 0; k < sizeFirst ; k++){
        while(index < sizeSecond && second[index] != first[k]){index++;}
        if(index >= sizeSecond){return 0;}
        index++;
    }
    return 1;
}

int main(){

    int numCases; scanf("%d\n",&numCases);
    while(numCases--){
        string names; getline(cin, names);
        size_t space = names.find(' ');
        string M = names.substr(0,space);
        string W = names.substr(space + 1);
        if(checkSubsequence(M,W) || checkSubsequence(W,M)){printf("YES\n");}
        else{printf("NO\n");}
    }

    return 0;
}
