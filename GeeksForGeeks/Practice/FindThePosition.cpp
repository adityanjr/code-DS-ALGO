#include <iostream>

using namespace std;

// void make(string curr, int index, string s, int& ans){
//     if(curr == s){
//         ans = index;
//         return;
//     }
//     else if(curr.size() > s.size()){
//         return;
//     }
    
//     make(curr + "4", 2*index+1, s, ans);
//     make(curr + "7", 2*index+2, s, ans);
// }

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string s;
	    cin >> s;
	    
	    
	   // int ans = 1;
	    
    //     make("4", 1, s, ans);
    //     make("7", 2, s, ans);
	    
	    long long int ans = 0;
	    
	    for(int i = 0; i < s.size(); i++){
	        ans = ans*2 + 1;
	        if(s[i] == '7'){
	             ans++;
	        }
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
