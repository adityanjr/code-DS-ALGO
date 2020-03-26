#include <iostream>

using namespace std;

void swap(char& c, char& d){
    char temp = c;
    c = d;
    d = temp;
}

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string s;
	    cin >> s;
	    
	    int n = s.size();
	    int last = s[n-1] - '0', ind = -1;
	    
	    for(int i = 0; i < n-1; i++){
	        if((s[i]-'0')%2 == 0){
                if(last > s[i]-'0'){
                    ind = i;
                    break;
                }
                else{
                    ind = i;
                }
                // else if(ind == -1){
                //     ind = i;
                // }
                // else if(s[ind] >= s[i]){
                //     ind = i;
                // }
	        }
	    }
	    
	    if(ind != -1){
	        swap(s[ind], s[n-1]);
	    }
	    
	    cout << s << endl;
	}
	
	return 0;
}
