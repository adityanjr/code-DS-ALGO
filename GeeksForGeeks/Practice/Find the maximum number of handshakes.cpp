#include <iostream>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    long long int n;
	    cin >> n;
	    
	    cout << (n*(n-1))/2 << endl;
	}
	
	return 0;
}
