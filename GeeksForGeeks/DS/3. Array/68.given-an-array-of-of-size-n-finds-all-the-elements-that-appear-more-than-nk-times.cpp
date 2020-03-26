// http://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times

#include <iostream>
#include "array.h"

struct ele {
	int a;
	int count;
};

int count(int *a, int x, int n){
	int c = 0;
	for(int i=0; i<n; i++){
		if(a[i] == x)
			c++;
	}
	return c;
}

void moreThanNdK(int *a, int n, int k){
	int r = int(n/k);
	ele b[k-1];
	for(int i=0; i<k-1; i++){
		b[i].a = -1;
		b[i].count = -1;
	}
	int size = 0;
	for(int i=0; i<n; i++){
		if(size < k-1){
			for(int j=0; j<k-1; j++){
				if(b[j].count == -1){
					b[j].a = a[i];
					b[j].count = 1;
					size++;
					break;
				}
			}
			continue;
		}
		bool find = false;
		int idx = -1;
		for(int j=0; j<k-1; j++){
			if(b[j].count >= 0 && b[j].a == a[i]){
				find = true;
				b[j].count++;
			}
		}
		if(!find){
			for(int j=0; j<k-1; j++){
				if(b[j].count > 0){
					b[j].count--;
				}
				else{
					b[j].count = -1;
					b[j].a = -1;
					size--;
				}
			}
		}
	}
	for(int i=0; i<k-1; i++){
		int c = count(a, b[i].a, n);
		if(c > n/k)
			cout<<b[i].a<<" "<<c<<'\n';
	}
	
}

int main(){
	cout << "First Test\n";
    int arr1[] = {4, 5, 6, 7, 8, 4, 4};
    int size = sizeof(arr1)/sizeof(arr1[0]);
    int k = 3;
    moreThanNdK(arr1, size, k);

    cout << "\nSecond Test\n";
    int arr2[] = {4, 2, 2, 7};
    size = sizeof(arr2)/sizeof(arr2[0]);
    k = 3;
    moreThanNdK(arr2, size, k);
 
    cout << "\nThird Test\n";
    int arr3[] = {2, 7, 2};
    size = sizeof(arr3)/sizeof(arr3[0]);
    k = 2;
    moreThanNdK(arr3, size, k);
 
    cout << "\nFourth Test\n";
    int arr4[] = {2, 3, 3, 2};
    size = sizeof(arr4)/sizeof(arr4[0]);
    k = 3;
    moreThanNdK(arr4, size, k);

	return 0;
}

