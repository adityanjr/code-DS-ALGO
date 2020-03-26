#include <iostream>
#include <vector>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, len = 10000;
	    cin >> n;
	    
	    vector<string> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	        int s = temp[i].size();
	        len = min(len, s);
	    }
	    
	    string ans = "";
	    int flag = 1;
	    
	    for(int i = 0; i < len; i++){
	        char c = ' ';
	        for(int j = 0; j < n; j++){
	            if(c == ' '){
	                c = temp[j][i];
	            }
	            else if(temp[j][i] != c){
	                flag = 0;
	                break;
	            }
	        }
	        if(!flag){
	            break;
	        }
	        ans += temp[0][i];
	    }
	    
	    if(ans.size() == 0){
	        cout << "-1";
	    }
	    else{
	        cout << ans;
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
