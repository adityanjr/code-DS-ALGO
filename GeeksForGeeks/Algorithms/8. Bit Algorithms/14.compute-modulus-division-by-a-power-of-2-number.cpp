//

#include <bits/stdc++.h>
using namespace std;

unsigned int getModulo(unsigned int n, unsigned int d) {
  return ( n & (d-1) );
}

/* Driver program to test above function */
int main() {
  unsigned int n = 6;
  unsigned int d = 4; /*d must be a power of 2*/
  printf("%u moduo %u is %u", n, d, getModulo(n, d));

  getchar();
  return 0;
}
