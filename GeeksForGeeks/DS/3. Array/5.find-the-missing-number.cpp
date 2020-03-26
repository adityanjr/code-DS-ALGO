// http://www.geeksforgeeks.org/find-the-missing-number

#include <iostream>
using namespace std;

int getMissingNo(int *a, int n){
	int x=0;
	for(int i=0; i<n; i++){
		x = x^(i+1);
		x = x^a[i];
	}
	x = x^(n+1);
	return x;
}

int main()
{
    int a[] = {1, 2, 4, 5, 6};
    int miss = getMissingNo(a, 5);
    printf("%d", miss);
}
