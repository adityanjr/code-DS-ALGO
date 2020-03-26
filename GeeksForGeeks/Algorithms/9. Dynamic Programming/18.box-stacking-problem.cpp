// http://www.geeksforgeeks.org/dynamic-programming-set-21-box-stacking-problem

#include <iostream>
#include <algorithm>
using namespace std;

struct Box {
  // h –> height, w –> width, d –> depth
  int h, w, d;  // for simplicity of solution, always keep w <= d
};

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

bool compare(Box a, Box b){
	return a.w*a.d < b.w*b.d;
}

Box *generateRotations(Box *box, int n){
	Box *b = new Box[3*n];
	for(int i=0; i<n; i++){
		int low = box[i].h;
		int medium = box[i].w;
		int high = box[i].d;
		if(medium < low && medium < high){
			swap(medium, low);
		}
		else if(high < low)
			swap(high, low);
		if(high < medium)
			swap(high, medium);
			
		b[3*i].h = low;
		b[3*i].w = medium;
		b[3*i].d = high;
		
		b[3*i+1].h = medium;
		b[3*i+1].w = low;
		b[3*i+1].d = high;

 		b[3*i+2].h = high;
		b[3*i+2].w = low;
		b[3*i+2].d = medium;
	}
	return b;
}

int maxStackHeight(Box *box, int n){
	box = generateRotations(box, n);
	sort(box, box+3*n, compare);
	n = 3*n;
	int cache[n];
	for(int i=0; i<n; i++)
		cache[i] = box[i].h;
	int m;
	for(int i=1; i<n; i++){
		m = cache[i];
		for(int j=0; j<i; j++){
			if(box[i].w > box[j].w && box[i].d > box[j].d)
				m = max(m, cache[i] + cache[j]);
		}
		cache[i] = m;
	}
	m = cache[0];
	for(int i=0; i<n; i++){
		m = max(m, cache[i]);
	}
	return m;
}

int main(){
	Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
  	int n = sizeof(arr)/sizeof(arr[0]);
  	printf("The maximum possible height of stack is %d\n", maxStackHeight (arr, n) );
	return 0;
}

