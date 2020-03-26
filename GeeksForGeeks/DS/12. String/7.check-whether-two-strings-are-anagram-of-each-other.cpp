// http://www.geeksforgeeks.org/check-whether-two-strings-are-anagram-of-each-other

#include <bits/stdc++.h>
using namespace std;

bool areAnagram(char *a, char *b, int n){
	long long unsigned int x = 0;
	for(int i=0; i<n; i++){
		x ^= a[i];
		x ^= b[i];
	}
	if(x == 0)
		return true;
	return false;
}

int main(){
	int n = 1000*256;
	char str1[n];
    char str2[n];
    for(int i=0; i<n; i++){
    	str1[i] = char('a' + i%256);
    	str2[n-i-1] = char('a' + i%256);
    	//cout<<str1[i]<<" ";
    }
/*    cout<<'\n';
    for(int i=0; i<n; i++)
		cout<<str2[i]<<" ";
		cout<<'\n';*/
    if ( areAnagram(str1, str2, n) )
      printf("The two strings are anagram of each other");
    else
      printf("The two strings are not anagram of each other");
	return 0;
}

