#include <iostream>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    long int n;
	    cin >> n;
	    
	    long long int total = (n*(n+1))/2, even = (n/2)*(n/2+1);
	   // cout << total << endl;
	   // cout << even << endl;
	    cout << total - even << " " << even << endl;
	}
	
	return 0;
}
