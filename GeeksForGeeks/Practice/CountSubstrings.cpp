#include <iostream>
#include <cmath>
#include <string>

using namespace std;

long long int getAns(int count){
    if(count < 2){
        return 0;
    }
    else if(count == 2){
        return 1;
    }
    
    long long int ans = (count * (count-1))/2;
    
    return ans;
}

int main() {
	int test;
	cin >> test;
	
	while(test){
	    string s;
	    cin >> s;
	    
	    int count = 0, n = s.size();
	    long long int ans = 0;
	    
	    for(int i = 0; i < n; i++){
	        if(s[i] == '1'){
	            count++;
	        }
	    }
	    
	    ans = getAns(count);
	    
	    cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
