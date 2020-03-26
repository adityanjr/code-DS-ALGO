// http://www.geeksforgeeks.org/check-for-identical-bsts-without-building-the-trees

#include <iostream>
#include "bst.h"

bool isSameBST(int *a, int *b, int n){
	 if(n<=0)
	     return true;
	 if(a[0] != b[0])
	     return false;
	 int tmp = a[0];
	 n--;
	 a++;	b++;
	 int al[n], ar[n], bl[n], br[n];
	 int j=0, k=0;
	 for(int i=0; i<n; i++){
	     if(a[i]<tmp){
 			  al[j] = a[i];
 			  j++;
  		 }
  		 else{
		 	  ar[k] = a[i];
		 	  k++;
         }
	 }
	 j=0, k=0;
	 for(int i=0; i<n; i++){
	     if(b[i]<tmp){
 			  bl[j] = b[i];
 			  j++;
  		 }
  		 else{
		 	  br[k] = b[i];
		 	  k++;
         }
	 }
	 return isSameBST(al, bl, j) && isSameBST(ar, br, k);
}

int main(){
	int a[] = {8, 3, 6, 1, 4, 7, 10, 14, 13};
   int b[] = {8, 10, 14, 3, 6, 4, 1, 7, 13};
   int n=sizeof(a)/sizeof(a[0]);
   printf("%s\n", isSameBST(a, b, n)?
             "BSTs are same":"BSTs not same");
   getchar();
}
