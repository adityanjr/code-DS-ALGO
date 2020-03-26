#include <iostream>
#include <vector>

using namespace std;

void rearrangeVector(vector<int>& vec, string s, int& start, int end){
    while(start < end){
        int index = s[start] - 'a';
        vec[index]--;
        start++;
        
        if(s[start-1] == s[end]){
            break;
        }
    }
    
}

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int k;
	    cin >> k;
	    
	    string s;
	    cin >> s;
	    
	    int i = 0, j = 0, n = s.size(), ans = 0;
	    
	    vector<int> vec(26, 0);
	    
	    while(i < n){
	        int c = s[i] - 'a';
            vec[c]++;
            if(vec[c] > k){
                rearrangeVector(vec, s, j, i);
            }

	        ans = max(i - j + 1, ans);
	        i++;
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
