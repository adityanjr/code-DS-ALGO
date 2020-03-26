#include <iostream>
using namespace std;

bool check(string a, string b){
    int i = 0, n = a.size(), m = b.size();
    
    if(n != m){
        return false;
    }
    
    bool ans1 = true, ans2 = true;
    
    // checking for clockwise rotation
    while(i < n){
        if(a[(i+2)%n] != b[i]){
            ans1 = false;
            break;
        }
        i++;
    }
    
    i = 0;
    
    // checking for anti-clockwise rotation
    while(i < n){
        if(b[(i+2)%n] != a[i]){
            ans2 = false;
            break;
        }
        i++;
    }
    
    return ans1 || ans2;
}

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string a, b;
	    cin >> a >> b;
	    
	    cout << check(a, b) << endl;
	}
	
	return 0;
}
