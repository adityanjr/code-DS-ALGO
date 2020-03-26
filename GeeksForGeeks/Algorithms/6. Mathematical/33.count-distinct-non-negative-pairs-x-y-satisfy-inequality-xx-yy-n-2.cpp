// http://www.geeksforgeeks.org/count-distinct-non-negative-pairs-x-y-satisfy-inequality-xx-yy-n-2/

#include <iostream>
#include <cmath>
using namespace std;

//x*x + y*y < n;
int countSolutions(int n){
	int sq = sqrt(n);
	int res = 0;
	if(sq*sq == n)
		sq--;
	for(int x=0; x<=sq; x++){
		int high = n-x*x;
		int s = sqrt(high);
		if(s*s == high)
			s--;
		res += (s+1);
	}
	return res;
}

int main(){
	cout << "Total Number of distinct Non-Negative pairs is "
         << countSolutions(6) << endl;
	return 0;
}

