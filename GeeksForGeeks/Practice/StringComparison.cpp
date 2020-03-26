#include <iostream>
using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string s1, s2;
	    cin >> s1 >> s2;
	    
	    int n1 = s1.size(), n2 = s2.size(), ans = 0, i = 0, j = 0;
	    
	    while(i < n1 && j < n2){
	        float p1 = s1[i], p2 = s2[i];
	        if(s1[i] == 'n' && i+1 < n1){
	            if(s1[i+1] == 'g'){
	                p1 += 0.5;
	                i++;
	            }
	        }
	        if(s2[j] == 'n' && j+1 < n2){
	            if(s2[j+1] == 'g'){
	                p2 += 0.5;
	                j++;
	            }
	        }
	        if(p1 > p2){
	            ans = 1;
	            break;
	        }
	        else if(p1 < p2){
	            ans = -1;
	            break;
	        }
	        i++;
	        j++;
	    }
	    
	    if(i == n1 && ans == 0 && j < n2){
	        ans = -1;
	    }
	    else if(j == n2 && ans == 0 && i < n1){
	        ans = 1;
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
