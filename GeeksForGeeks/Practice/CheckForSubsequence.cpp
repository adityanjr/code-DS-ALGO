#include <iostream>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string a, b;
	    cin >> a >> b;
	    
	    int i = 0, j = 0, alen = a.size(), blen = b.size();
	    
	    while(i < blen && j < alen){
	        if(a[j] == b[i]){
	            j++;
	        }
	        i++;
	    }
	    
	    cout << (j == alen) << endl;
	}
	
	return 0;
}
