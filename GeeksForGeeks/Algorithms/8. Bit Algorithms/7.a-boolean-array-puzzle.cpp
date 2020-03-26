// http://www.geeksforgeeks.org/a-boolean-array-puzzle

#include <bits/stdc++.h>
using namespace std;

void changeToZero(int a[2]){
	/*Method 1 */
	//a[a[1]] = a[!a[1]];
	
	/*Method 2 */
	//a[!a[0]] = a[!a[1]];
	
	a[a[1]] = a[a[0]];
}

int main(){
	 int a[] = {0, 1};
  	 changeToZero(a);

  	 printf(" arr[0] = %d \n", a[0]);
 	 printf(" arr[1] = %d ", a[1]);
 	 getchar();
	return 0;
}

