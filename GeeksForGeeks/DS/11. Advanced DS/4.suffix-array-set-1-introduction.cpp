// http://www.geeksforgeeks.org/suffix-array-set-1-introduction/

#include <bits/stdc++.h>
using namespace std;

struct suffixes {
	int idx;
	char *suf;
};

bool Compare(suffixes a, suffixes b){
	return (strcmp(a.suf, b.suf) < 0);
}

int* buildSuffixArray(char *txt, int n){
	suffixes s[n];
	int *res = new int[n];
	for(int i=0; i<n; i++){
		s[i].idx = i;
		s[i].suf = txt+i;
	}
	sort(s, s+n, Compare);
	for(int i=0; i<n; i++){
		res[i] = s[i].idx;
	}
	return res;
}

void search(char *pat, char *txt, int *arr, int n){
	int m = strlen(pat);
	int l = 0, r = n-1;
	while(l <= r){
		int mid = l + (r-l)/2;
		int res = strncmp(pat, txt+arr[mid], m);
		if(res == 0){
			cout<<"Found at "<<arr[mid];
			return;
		}
		if(res < 0){
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	cout<"Nope";
}

int main(){
	char txt[] = "banana";  // text
    char pat[] = "nan";   // pattern to be searched in text

    // Build suffix array
    int n = strlen(txt);
    int *suffArr = buildSuffixArray(txt, n);

    // search pat in txt using the built suffix array
    search(pat, txt, suffArr, n);
	return 0;
}

