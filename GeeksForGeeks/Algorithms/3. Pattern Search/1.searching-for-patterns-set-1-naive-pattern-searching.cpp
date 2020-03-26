// http://www.geeksforgeeks.org/searching-for-patterns-set-1-naive-pattern-searching

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void search(char *pat, char *txt){
	int N = strlen(txt);
	int M = strlen(pat);
	for(int i=0; i<N-M; i++){
		int tmp = i;
		int j=0;
		while(txt[tmp] == pat[j]){
			tmp++;  j++;
		}
		if(j == M){
			cout<<i<<" ";
		}
	}
}

int main(){
	char *txt = "AABAACAADAABAAABAA";
   	char *pat = "AABA";
   	search(pat, txt);
	return 0;
}

