// http://www.geeksforgeeks.org/lexicographic-permutations-of-string/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int compare (char a, char b){
	return ( int(a) < int(b) );
}

// A utility function two swap two characters a and b
void swap (char* a, char* b){
    char t = *a;
    *a = *b;
    *b = t;
}

int ceilIndex(char *str, char f, int low, int high){
	int j=low;
	for(int i=low+1; i<=high; i++){
		if(str[i] > f && str[i] < str[j])
			j = i;
	}
	return j;
}

void reverse(char *str, int low, int high){
	while(low < high){
		swap(&str[low], &str[high]);
		low++;  high--;
	}
}

void sortedPermutations(char *str){
	int n = strlen(str);
	sort(str, str+n, compare);
	cout<<str<<'\n';
	int i;
	while(1){
		for(i=n-2; i>=0; i--){
			if(str[i+1] > str[i])
				break;
		}
		if(i==-1)
			break;
		int idx = ceilIndex(str, str[i], i+1, n-1);
		swap(&str[idx], &str[i]);
		reverse(str, i+1, n-1);
		cout<<str<<'\n';
	}
}

int main(){
	char str[] = "ABCD";
    sortedPermutations(str);
	return 0;
}

