#include <iostream>

using namespace std;

int hcf(int a, int b){
    if(a == 0){
        return b;
    }
    return hcf(b%a, a);
}

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, m;
	    cin >> n >> m;
	    
	    int num = hcf(n, m);
	    
	    cout << n/num + m/num << endl;
	}
	
	return 0;
}
