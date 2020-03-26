// http://www.geeksforgeeks.org/online-algorithm-for-checking-palindrome-in-a-stream/

#include <iostream>
#include <cstring>
#include "array.h"

#define d 256

#define q 103	//prime

void checkPalindromes(char *txt){
	int N = strlen(txt);
	cout<<txt[0]<<": YES"<<'\n';
	int first = txt[0]%q;
	int second = txt[1]%q;
	int h=1;
	for(int i=1; i<N; i++){
		if(first == second){
			int j=0;
			for(; j<i/2; j++){
				if(txt[j] != txt[i-j]){
					break;
				}
			}
			if(j == i/2){
				cout<<txt[i]<<": YES"<<'\n';	
			}
			else {
				cout<<txt[i]<<": NO"<<'\n';
			}
		}
		else
			cout<<txt[i]<<": NO"<<'\n';
		if(i != N-1) {
			if(i%2 == 0){
				h = (h*d)%q;
				first =(first + h*txt[i/2])%q;
				second = (second*d + txt[i+1])%q; 
			}
			else {
				second = (d*(second + q - txt[(i+1)/2]*h)%q + txt[i+1])%q;
			}
		}
	}
}

int main(){
	char *txt = "aabaacaabaa";
    checkPalindromes(txt);
	return 0;
}

