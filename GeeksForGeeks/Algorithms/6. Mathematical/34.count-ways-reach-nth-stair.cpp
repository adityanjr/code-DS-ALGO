// http://www.geeksforgeeks.org/count-ways-reach-nth-stair

#include <iostream>
#include <cstring>
using namespace std;

static int count = 0;
int countWays(int n){
	count++;
	if(n == 1)
		return 1;
	if(n == 2)
		return 2;
	return countWays(n-1) + countWays(n-2);
}

long long int countWaysDP(int n, long long int *help){
	if(n<3 || help[n] != 0)
		return help[n];
	help[n] = countWaysDP(n-1, help) + countWaysDP(n-2, help);
	return help[n];
}

int main(){
	int s = 4;
  	printf("Number of ways = %d\n", countWays(s));
  	s = 80;
	long long int help[s+1];
	memset(help, 0, sizeof(help));
	help[0] = 0;
	help[1] = 1;
	help[2] = 2;
	cout<<countWaysDP(s, help);
	return 0;
}

