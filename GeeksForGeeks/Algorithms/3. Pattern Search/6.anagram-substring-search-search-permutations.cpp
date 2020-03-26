// http://www.geeksforgeeks.org/anagram-substring-search-search-permutations

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX 256

bool compare(int *a, int *b){
    for(int i=0; i<MAX; i++){
        if(a[i] != b[i])
            return false;
    }
    return true;
}

void search(char *pat, char *txt){
    int M = strlen(pat);
    int N = strlen(txt);
    int countP[MAX] = {0}, countT[MAX] = {0};
    int i=0;
    for(; i<M; i++){
        countP[int(pat[i])]++;
        countT[int(txt[i])]++;
    }
    for(i=M; i<N; i++){
        if(compare(countP, countT)){
            cout<<i-M<<" ";
        }
        countT[int(txt[i])]++;
        countT[int(txt[i-M])]--;
    }
    if(compare(countP, countT)){
        cout<<i-M<<" ";
    }
}

int main(){
    char txt[] = "BACDGABCDA";
    char pat[] = "ABCD";
    search(pat, txt);
    return 0;
}
