#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int n, ans = 0;
	    cin >> n;
	    
	    vector<int> A(n);
	    vector<int> B(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> A[i];
	    }
	    
	    for(int i = 0; i < n; i++){
	        cin >> B[i];
	    }
	    
	    sort(A.begin(), A.end());
	    sort(B.begin(), B.end(), greater<int>());
	    
	    for(int i = 0; i < n; i++){
	        ans = ans + A[i]*B[i];
	    }
	    
	    cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
