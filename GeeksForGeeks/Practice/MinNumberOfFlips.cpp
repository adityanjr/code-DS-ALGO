// http://www.practice.geeksforgeeks.org/problem-page.php?pid=1450

#include <iostream>
#include <string>

using namespace std;

int main() {
	int test;
	cin >> test;
	
	while(test){
	    string s;
	    cin >> s;
	    
	    int ans0 = 0, ans1 = 0;
	    
	    for(int i = 0; i < s.size(); i++){
	        if(i%2 == 0){
	            if(s[i] == '1'){
	                ans1++;
	            }
	            else{
	                ans0++;
	            }
	        }
	        else{
	            if(s[i] == '1'){
	                ans0++;
	            }
	            else{
	                ans1++;
	            }
	        }
	    }
	    
	    cout << min(ans0, ans1) << endl;
	    
	    test--;
	}
	
	return 0;
}
