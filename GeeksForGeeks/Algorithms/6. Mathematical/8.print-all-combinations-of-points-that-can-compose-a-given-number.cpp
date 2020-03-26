// http://www.geeksforgeeks.org/print-all-combinations-of-points-that-can-compose-a-given-number

#include <iostream>
#include <cstdio>
using namespace std;

void printCompositions(int n, string res){
	if(n<=0){
		cout<<res<<'\n';
		return;
	}
	if(n>0)
		printCompositions(n-1, res+"1 ");
	if(n>1)
		printCompositions(n-2., res+"2 ");
	if(n>2)
		printCompositions(n-3, res+"3 ");
}

int main(){
	int n = 4;
  	printf("Differnt compositions formed by 1, 2 and 3 of %d are\n", n);
  	printCompositions(n, "");
	return 0;
}

