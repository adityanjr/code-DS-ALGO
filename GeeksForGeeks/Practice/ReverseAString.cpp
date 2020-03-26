#include <iostream>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
    while(test--){
        string s;
        cin >> s;
        
        int n = s.size();
        
        for(int i = 0; i < n/2; i++){
            char c = s[i];
            s[i] = s[n-i-1];
            s[n-i-1] = ca;
        }
        
        cout << s << endl;
    }
	
	return 0;
}
