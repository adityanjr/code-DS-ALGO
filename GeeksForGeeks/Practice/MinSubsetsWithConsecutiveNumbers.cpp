// http://www.practice.geeksforgeeks.org/problem-page.php?pid=1531

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int n;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    sort(temp.begin(), temp.end());
	    
	    int ans = 1, i = 1;
	    
	    LOOP:while(i < n){
	        if(temp[i] == temp[i-1]){
	            i++;
	            goto LOOP;
	        }
	        if(temp[i] - temp[i-1] != 1){
	            ans++;
	        }
	        i++;
	    }
	    
	    cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
