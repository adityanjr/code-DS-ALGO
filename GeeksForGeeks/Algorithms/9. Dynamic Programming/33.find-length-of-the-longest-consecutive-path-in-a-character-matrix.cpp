// http://www.geeksforgeeks.org/find-length-of-the-longest-consecutive-path-in-a-character-matrix

#include <bits/stdc++.h>
using namespace std;

#define R 3
#define C 3

int x[] = {0, 1, 1, -1, 1, 0, -1, -1};
int y[] = {1, 0, 1, 1, -1, -1, 0, -1};
int cache[R][C];

bool isSafe(int i, int j){
	if(i<0 || i>=R || j<0 || j>=C)
		return false;
	return true;
}

int bar(char mat[R][C], int i, int j, char cur){
	if(cache[i][j] != -1)
		return cache[i][j];
	cache[i][j] = 1;
	for(int k=0; k<8; k++){
		int idx = i+x[k];
		int idy = j+y[k];
		if(isSafe(idx, idy) && int(mat[idx][idy]) == int(cur) + 1){
			cache[i][j] = max(cache[i][j], 1 + bar(mat, idx, idy, mat[idx][idy]));
		}
	}
	return cache[i][j];
}

int getLen(char mat[R][C], char start){
	memset(cache, -1, sizeof(int)*R*C);
	int ans = 0;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(mat[i][j] == start){
				ans = max(ans, bar(mat, i, j, start));
			}
		}
	}
	return ans;
}

int main(){
	char mat[R][C] = { {'a','c','d'},
                     { 'h','b','e'},
                     { 'i','g','a'}};
    cout << getLen(mat, 'a') << endl;
    cout << getLen(mat, 'e') << endl;
    cout << getLen(mat, 'b') << endl;
    cout << getLen(mat, 'f') << endl;
}
