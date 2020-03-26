#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int n, x;
	    cin >> n >> x;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    sort(temp.begin(), temp.end());
	    
	    int i = 0, j = n-1;
	    
	    string ans = "No";
	    
	    while(i < j){
	        int sum = temp[i] + temp[j];
	        
	        if(sum == x){
	            ans = "Yes";
	            break;    
	        }
	        else if(sum > x){
	            j--;
	        }
	        else{
	            i++;
	        }
	    }
	    
	    cout << ans << endl;
	    
	    test--;
	}
	
	
	return 0;
}
