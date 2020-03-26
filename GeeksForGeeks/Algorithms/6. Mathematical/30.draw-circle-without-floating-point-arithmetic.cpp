// http://geeksquiz.com/draw-circle-without-floating-point-arithmetic

#include <iostream>
#include <cstdio>
using namespace std;

void drawCircle(int r) {
	int x, y;
	for(int i=0; i<2*r+1; i++){
		for(int j=0; j<2*r+1; j++){
			x = i-r;
			y = j-r;
			if(x*x + y*y <= r*r){
				cout<<". ";
			}
			else{
				cout<<"  ";
			}
		}
		cout<<'\n';
	}
}

int main(){
	drawCircle(8);
	return 0;
}

