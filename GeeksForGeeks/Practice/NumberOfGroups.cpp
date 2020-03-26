#include <iostream>
#include <map>

using namespace std;

int comb(int n){
    if(n < 3){
        return 0;
    }
    
    int ans = 1;
    
    for(int i = 0; i < 3; i++){
        ans = ans*n;
        n--;
    }
    
    for(int i = 1; i <= 3; i++){
        ans = ans/i;
    }
    
    return ans;
}

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n;
	    cin >> n;
	    
	    long long ans = 0;
	    
	    map<int, int> m;
	    m[0] = 0, m[1] = 0, m[2] = 0;
	    
	    for(int i = 0; i < n; i++){
	        int num;
	        cin >> num;
	        
	        num = num%3;
	        m[num]++;
	    }
	    
	    // Group of 2 will be formed by the choosing any 2 which are divisible by 3 or choosing 2, one out of which
	    // leaves remainder 1 & the other leaves a remainder 2 on division by 3.
        // Group of 3 (m[0], m[0], m[0]) || (m[1], m[1], m[1]) || (m[2], m[2], m[2])|| (m[0], m[1], m[2])
        if(m[0]){
            ans += (((m[0])*(m[0]-1))/2);    
            // ans += ((m[0]-1)*(m[0]-2))/2;
            ans += comb(m[0]);
        }
        if(m[1]){
            // ans += ((m[1]-1)*(m[1]-2))/2;    
            ans += comb(m[1]);
        }
        if(m[2]){
            // ans += ((m[2]-1)*(m[2]-2))/2;
            ans += comb(m[2]);
        }
        
        ans += (m[1]*m[2]);
        ans += m[0]*m[1]*m[2];
        
        cout << ans << endl;
	}
	
	return 0;
}
