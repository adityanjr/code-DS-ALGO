#include <iostream>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string s1, s2, ans = "";
	    cin >> s1 >> s2;
	    
	    int i = 0, j = 0, n1 = s1.size(), n2 = s2.size();
	    
	    bool first = true;
	    
	    while(i < n1 && j < n2){
	        if(first){
	            ans += s1[i];
	            i++;
	        }
	        else{
	            ans += s2[j];
	            j++;
	        }
	        first = !first;
	    }
	    
	    while(i < n1){
	        ans += s1[i];
            i++;
	    }
	    
	    while(j < n2){
	        ans += s2[j];
            j++;
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
