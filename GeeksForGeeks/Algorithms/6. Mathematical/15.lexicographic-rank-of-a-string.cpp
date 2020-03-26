// http://www.geeksforgeeks.org/lexicographic-rank-of-a-string

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX 256

int fact(int n) {
    return (n <= 1)? 1 :n * fact(n-1);
}

// Construct a count array where value at every index
// contains count of smaller characters in whole string
void populateAndIncreaseCount(int* count, char* str){
    int i;
    for( i = 0; str[i]; ++i )
        ++count[ str[i] ];

    for( i = 1; i < 256; ++i )
        count[i] += count[i-1];
}

// Removes a character ch from count[] array
// constructed by populateAndIncreaseCount()
void updateCount (int* count, char ch){
    int i;
    for( i = ch; i < MAX; ++i )
        --count[i];
}

int findRank(char *str){
	int len = strlen(str);
	int mul = fact(len);
	int rank = 1;
	int i;
	int count[MAX]= {0};
	populateAndIncreaseCount(count, str);
	for(int i=0; i< len; i++){
		mul /= len - i;
		rank += count[str[i]-1]*mul;
		updateCount(count, str[i]);
	}
	return rank;
}

int main(){
	char str[] = "string";
    printf ("%d", findRank(str));
	return 0;
}

