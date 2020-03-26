#include <iostream>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, money;
	    cin >> n >> money;
	    
	    cout << ((n+1)/2)*money << endl;
	}
	
	return 0;
}
