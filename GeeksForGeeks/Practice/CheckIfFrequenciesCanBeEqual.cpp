#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test){
	    string s;
	    cin >> s;
	    
	    int n = s.size();
	    
	    map<char, int> m;
	    
	    for(int i = 0; i < n; i++){
	        if(m.find(s[i]) == m.end()){
	            m[s[i]] = 1;
	        }
	        else{
	            m[s[i]]++;
	        }
	    }
	    
	    int count1 = -1, count2 = -1, ans = 1, num1 = 0, num2 = 0;
	    
	    map<char, int> :: iterator it = m.begin();
	    
	    while(it != m.end()){
	       // cout << it->first << " " << it->second << endl;
	        if((count1 == -1) || (count1 == it->second)){
	            count1 = it->second;
	            num1++;
	        }
	        else if((count2 == -1) || (count2 == it->second)){
	            count2 = it->second;
	            num2++;
	        }
	        else{
	            ans = 0;
	            goto ANS;
	        }
	        it++;
	    }
	    
	    if(count1 == -1 || count2 == -1){
	        ans = 1;
	    }
	    else if(abs(count1 - count2) > 1){
	        ans = 0;
	    }
	    else if(num1 != 0 || num2 != 0){
	        if(!(num1 == 1 || num2 == 1)){
	            ans = 0;
	        }
	    }
	    
	    ANS:cout << ans << endl;
	    
	    test--;
	}
	
	
	return 0;
}
