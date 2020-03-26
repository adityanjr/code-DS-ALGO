#include <iostream>
#include <cmath>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n;
	    cin >> n;
	    
	    int det = sqrt(1 + 4*n*2);
	    
	    cout << (-1+det)/2 << endl;
	}
	
	return 0;
}
