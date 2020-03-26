// http://www.geeksforgeeks.org/given-a-number-find-next-smallest-palindrome-larger-than-this-number

#include <iostream>
#include <cstdio>
using namespace std;

bool all9(int *num, int n){
	for(int i=0; i<n; i++){
		if(num[i] != 9)
			return false;
	}
	cout<<1<<" ";
	for(int i=0; i<n-1; i++){
		cout<<0<<" ";
	}
	cout<<1;
	return true;
}

int addOne(int *num, int n){
	int carry = 1;
	for(int i=n-1; i>=0 && carry; i--){
		int a = num[i]+1;
		num[i] = a%10;
		carry = a/10;
	}
}

void nextPalindrome(int *num, int n){
	if(all9(num, n)){
		return;
	}
	int i, j;
	if(n%2){
		i=(n-1)/2-1;
		j=(n-1)/2 + 1;
	}
	else {
		i = n/2-1;
		j = n/2;
	}
	while(i>=0 && j<n){
		if(num[i] < num[j]){
			if(n%2){
				addOne(num, n/2+1);
			}
			else {
				addOne(num, n/2);
			}
			break;
		}
		i--;    j++;
		
	}
	i=0;
	j=n-1;
	while(i<j){
		num[j] = num[i];
		i++;    j--;
	}
	for(int i=0; i<n; i++)
		cout<<num[i]<<" ";
}

int main(){
	int num[] = {9, 4, 1, 8, 7, 9, 7, 8, 3, 2};
    int n = sizeof (num)/ sizeof(num[0]);
    nextPalindrome( num, n );
	return 0;
}

