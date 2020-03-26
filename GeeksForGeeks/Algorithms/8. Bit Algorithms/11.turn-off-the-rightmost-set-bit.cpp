//

#include <bits/stdc++.h>
using namespace std;

int fun(unsigned int n){
  return n&(n-1);
}

/* Driver program to test above function */
int main(){
  int n = 7;
  printf("The number after unsetting the rightmost set bit %d", fun(n));

  getchar();
  return 0;
}
