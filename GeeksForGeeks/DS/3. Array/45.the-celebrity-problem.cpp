// http://www.geeksforgeeks.org/the-celebrity-problem/

#include <iostream>
#include <stack>
#include "array.h"

#define N 8
 
// Celebrities identified with numbers from 0 through size-1
 
bool HaveAcquiantance(bool MATRIX[N][N], int a, int b){
	return MATRIX[a][b];
}

int CelebrityUsingStack(bool MATRIX[N][N], int n){
	stack<int> s;
	for(int i=0; i<n; i++){
		s.push(i);
	}
	while(s.size() > 1){
		int tmp = s.top(); s.pop();
		int tmp1 = s.top(); s.pop();
		if(HaveAcquiantance(MATRIX, tmp, tmp1)){
			s.push(tmp1);
		}
		else{
			s.push(tmp);
		}
 	}
 	return s.top();
}

int main(){
	int size = 4;
	// Person with 2 is celebrity
	bool MATRIX[N][N] = {{0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}};
	
	int id = CelebrityUsingStack(MATRIX, size);
	id == -1 ? cout << "No celebrity" : cout << "Celebrity ID " << id;
	return 0;
}
