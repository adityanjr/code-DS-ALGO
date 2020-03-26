//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct suffix {
    int idx;
    char *suff;
};

bool compare(suffix a, suffix b){
    return strcmp(a.suff, b.suff) < 0 ? 1:0;
}

int *buildSuffixarray(char *txt, int n){
    suffix suffixes[n];
    for(int i=0; i<n; i++){
        suffixes[i].idx = i;
        suffixes[i].suff = txt+i;
    }
    sort(suffixes, suffixes+n, compare);
    int *s = new int[n];
    for(int i=0; i<n; i++){
        s[i] = suffixes[i].idx;
    }
    return s;
}

void printArray(int *a, int n){
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<'\n';
}

void search(char *pat, char *txt, int *suffArray, int n){
    int m = strlen(pat);

    int start = 0, end = n-1;
    while(start<=end){
        int mid = (end+start)/2;
        int res = strncmp(pat, txt+suffArray[mid], m);
        if(res == 0){
            cout<<suffArray[mid]<<" ";
            return;
        }
        if(res<0)
            end = mid - 1;
        else
            start = mid+1;
    }
    cout<<"Not found\n";
}

int main(){
    char *txt = "banana";
    char *pat = "nan";
    int n = strlen(txt);
    int *suf = buildSuffixarray(txt, n);
    //printArray(suf, n);
    search(pat, txt, suf, n);
    return 0;
}
