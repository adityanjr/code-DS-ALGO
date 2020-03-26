// http://www.geeksforgeeks.org/check-for-integer-overflow

#include <bits/stdc++.h>
using namespace std;

int addOvf(int *res, int x, int y){
	*res = x+y;
	if(x>0 && y>0 && *res < 0)
		*res = -1;
	else if(x<0 && y<0 && *res>0)
		*res = -1;
	return *res;
}

int main(){
	 int *res = (int *)malloc(sizeof(int));
     int x = 2147483640;
     int y = 10;

     printf("%d", addOvf(res, x, y));

     printf("\n %d", *res);
	return 0;
}

