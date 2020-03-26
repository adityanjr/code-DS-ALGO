// http://www.practice.geeksforgeeks.org/problem-page.php?pid=1482

#include <iostream>
#include <vector>

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
	    
	    int ans = temp[0], i = 1, check = temp[0];
	    
	    while(i < n){
	        if(temp[i] > temp[i-1]){
	            check = check + temp[i];
	        }
	        else{
	            ans = max(ans, check);
	            check = temp[i];
	        }
	        i++;
	    }
	    
	    cout <<  max(ans, check) << endl;
	    
	    test--;
	}
	
	return 0;
}
