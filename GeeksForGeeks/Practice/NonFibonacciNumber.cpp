#include <iostream>
using namespace std;

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int n;
	    cin >> n;
	    
	    int curr = 1, f1 = 1, f2 = 2, count = 0;
	    
	    while(count != n){
	        if(curr < f2 && curr > f1){
	            count++;
	            if(count == n){
	                break;
	            }
	            curr++;
	        }
	        else if(curr == f2 || curr == f1){   
	            curr++;
	        }
	        else{
	            int f0 = f1 + f2;
                f1 = f2;
                f2 = f0;
	        }
	    }
	    
	    cout << curr << endl;
	    
	    test--;
	}
	
	return 0;
}
