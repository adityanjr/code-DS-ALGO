// http://geeksquiz.com/c-program-for-tower-of-hanoi

#include <iostream>
#include <cstdio>
using namespace std;

void towerOfHanoi(int n, char from, char to, char buff){
	if(n == 1){
//		cout<<from<<"->"<<to<<"\n";
		return;
	}
	towerOfHanoi(n-1, from, buff, to);
//	cout<<from<<"->"<<to<<'\n';
	towerOfHanoi(n-1, buff, to, from);
}

int main(){
	int n = 4; // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B');
	return 0;
}

