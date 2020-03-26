// http://www.geeksforgeeks.org/stable-marriage-problem/

#include <iostream>
#include "array.h"
#include <cstring>
#define N 4

bool compatible(int a[][N], int *free, int man, int wman){
	for(int i=0; i<N; i++){
		if(a[wman][i] == free[wman]){
			return false;
		}
		else if(a[wman][i] == man){
			return true;
		}
	}
}

void stableMarriage(int a[][N]){
	int free[2*N];
	memset(free, -1, sizeof(free));
	int freeMen = N;
	while(freeMen > 0){
		int idxM = -1, idxW = -1;
		// Get Man
		for(int i=0; i<N; i++){
			if(free[i] == -1){
				idxM = i;
				break;
			}
		}
		//Get Woman
		for(int i=0; i<N; i++){
			if(free[a[idxM][i]] == -1){
				idxW = a[idxM][i];
				break;
			}
			else {
				if(compatible(a, free, idxM, a[idxM][i])){
					int man = free[a[idxM][i]];
					idxW = a[idxM][i];
					free[man] = -1;
					freeMen++;
				}
			}
		}
		free[idxM] = idxW;
		free[idxW] = idxM;
		freeMen--;
	}
	for(int i=0; i<N; i++)
		cout<<i<<"-->"<<free[i]<<'\n';
}

int main(){
	int prefer[2*N][N] = { {4, 5, 6, 7},
        {4, 5, 6, 7},
        {4, 5, 6, 7},
        {4, 5, 6, 7},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
    };
    stableMarriage(prefer);
	return 0;
}

