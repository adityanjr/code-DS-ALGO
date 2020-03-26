#include <iostream>
using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    long long int n, i = 1;
	    cin >> n;
	    
	    while(i < n){
	        i = i << 1;
	    }
	    
	    if(i == n){
	        cout << "YES";
	    }
	    else{
	        cout << "NO";
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
