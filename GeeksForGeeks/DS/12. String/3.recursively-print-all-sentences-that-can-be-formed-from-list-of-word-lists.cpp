// http://www.geeksforgeeks.org/recursively-print-all-sentences-that-can-be-formed-from-list-of-word-lists/

#include <bits/stdc++.h>
using namespace std;

#define R 3
#define C 3

void solve(string arr[R][C], string res, int r){
	if(r == R){
		cout<<res<<'\n';
		return;
	}
	for(int i=0; i<C; i++){
		if(arr[r][i] != ""){
			solve(arr, res + arr[r][i] + ' ', r+1);
		}
	}
}

void print(string arr[R][C]){
	solve(arr, "", 0);
}

int main(){
	string arr[R][C]  = {{"you", "we"},
                        {"have", "are"},
                        {"sleep", "eat", "drink"}};
 
   print(arr);
	return 0;
}