// http://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void computeLPS(char *pat, int M, int *lps){
	int len = 0;
	int i=1;
	lps[0] = 0;
	while(i<M){
		if(pat[i] == pat[len]){
			len++;
			lps[i] = len;
			i++;
		}
		else {
			if(len != 0){
				len = lps[len-1];
			}
			else {
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMPSearch(char *pat, char *txt) {
	int M = strlen(pat);
	int N = strlen(txt);
	int *lps = new int[M];
	computeLPS(pat, M, lps);
	int i=0, j=0;
	while(i < N){
		if(pat[j] == txt[i]){
			j++;
			i++;
		}
		if(j == M){
			cout<<i-M<<" ";
			j = lps[j-1];
		}
		else if(i<N && pat[j] != txt[i]) {
			if( j!= 0){
				j = lps[j-1];
			}
			else
				i++;
		}
	}
}

int main(){
	char *txt = "ABABDABACDABABCABAB";
	char *pat = "ABABCABAB";
	KMPSearch(pat, txt);
	return 0;
}

