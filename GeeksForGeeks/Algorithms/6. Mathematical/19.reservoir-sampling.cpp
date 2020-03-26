// http://www.geeksforgeeks.org/reservoir-sampling

#include <iostream>
#include <ctime>
using namespace std;

void selectKItems(int *stream, int n, int k){
	int reserve[k];
	for(int i=0; i<k; i++)
		reserve[i] = stream[i];
	srand(time(NULL));
	for(int i=k; i<n; i++){
		int j = rand()%(i+1);
		if(j<k){
			reserve[j] = stream[i];
		}
	}
	for(int i=0; i<k; i++)
		cout<<reserve[i]<<" ";
	delete[] reserve;
}

int main(){
	int stream[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int n = sizeof(stream)/sizeof(stream[0]);
    int k = 5;
    selectKItems(stream, n, k);
	return 0;
}

