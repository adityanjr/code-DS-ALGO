// http://www.geeksforgeeks.org/dynamic-programming-set-12-longest-palindromic-subsequence

#include <iostream>
#include <cstring>
using namespace std;

int lps(char *str){
    int len = strlen(str);
    int L[len][len];
    for(int i=0; i<len; i++){
        L[i][i] = 1;
    }
    int j;
    for(int cl=2; cl<=len; cl++){
        for(int i=0; i<len-cl+1; i++){
            j = i+cl-1;
            if(str[i] == str[j] && cl==2)
                L[i][j] = 2;
            else if(str[i] == str[j])
                L[i][j] = L[i+1][j-1] + 2;
            else {
                L[i][j] = max(L[i][j-1], L[i+1][j]);
            }
        }
    }
    return L[0][len-1];
}

int main() {
    char seq[] = "GEEKS FOR GEEKS";
    int n = strlen(seq);
    printf ("The lnegth of the LPS is %d", lps(seq));
	return 0;
}


