#include <iostream>
using namespace std;

int level(int x){
    int curr = 0, lev = 0;
    
    while(curr < x){
        lev++;
        curr = (curr << 1) + 1;
    }
    
    return lev;
}

int parent(int x){
    return x/2;
}

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int x, y;
	    cin >> x >> y;
	    
	    int xlev = level(x), ylev = level(y), xpar = x, ypar = y;
	    
	    while(xpar != ypar){
	        if(level(xpar) == level(ypar)){
	            xpar = parent(xpar);
	            ypar = parent(ypar);
	        }
	        else if(level(xpar) < level(ypar)){
	            ypar = parent(ypar);
	        }
	        else{
	            xpar = parent(xpar);
	        }
	    }
	    
	    cout << level(x) - level(xpar) + level(y) - level(ypar) << endl;
	}
	
	return 0;
}
