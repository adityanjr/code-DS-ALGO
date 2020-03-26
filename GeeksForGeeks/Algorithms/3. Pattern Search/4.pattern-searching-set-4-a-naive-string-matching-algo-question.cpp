//

#include <iostream>
#include <cstring>
using namespace std;

void search(char *pat, char *txt){
	int M = strlen(pat);
	int N = strlen(txt);
	int i=0;
	while(i<=N-M){
		int j=0;
		int tmp = i;
		while(txt[i] == pat[j] && i<N && j<M){
			i++;    j++;
		}
		if(j == M){
			cout<<tmp<<" ";
		}
		else {
			if(j == 0)
				i++;
		}
	}
}

int main(){
	char *txt = "ABABCDAABCD";
   	char *pat = "ABCD";
   	search(pat, txt);
	return 0;
}

