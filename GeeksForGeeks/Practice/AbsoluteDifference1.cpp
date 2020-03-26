#include <iostream>
#include <vector>

using namespace std;

bool condition(int num){
    string s = to_string(num);
    
    for(int i = 1; i < s.size(); i++){
        if(abs(s[i]-s[i-1]) != 1){
            return false;
        }
    }
    
    return true;
}

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, k, count = 0;
	    cin >> n >> k;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    for(int i = 0; i < n; i++){
	        if(temp[i] < k && condition(temp[i])){
	            count++;
	            cout << temp[i] << " ";
	        }
	    }
	    
	    if(!count){
	        cout << "-1";
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
