#include <iostream>
#include <cmath>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, m;
	    cin >> n >> m;
	    
	    cout << (int)(n/pow(2, m-1)) << endl;
	}
	
	return 0;
}
