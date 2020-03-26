// http://www.geeksforgeeks.org/multiply-two-numbers-without-using-multiply-division-bitwise-operators-and-no-loops

#include <iostream>
#include <cstdio>
using namespace std;

int multiply(int x, int y){
   /* 0  multiplied with anything gives 0 */
   if(y == 0)
     return 0;

   /* Add x one by one */
   if(y > 0 )
     return (x + multiply(x, y-1));

  /* the case where y is negative */
   if(y < 0 )
     return -multiply(x, -y);
}

int main() {
  printf("\n %d", multiply(5, -11));
  return 0;
}
