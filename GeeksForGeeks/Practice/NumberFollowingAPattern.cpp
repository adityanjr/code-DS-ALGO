#include <iostream>
#include <vector>

using namespace std;

int main() {
	int test;
	cin >> test;
	
	while(test){
	    string s;
	    cin >> s;
	    
	    int n = s.size(), i = 0, num = 1, last = 0;
	    
	    vector<int> temp(n+1);
	    
	    while(1){
	        while(s[i] != 'I' && i < n){
	            i++;
	        }
	        if(i == n){
	            temp[n] = num;
	            num++;
	            for(int j = i-1; j >= last; j--){
                    temp[j] = num;
                    num++;
                }
                break;
	        }
	        else{
	            temp[i] = num;
	            num++;
	            if(i != last){
	                for(int j = i-1; j >= last; j--){
	                    temp[j] = num;
	                    num++;
	                }
	            }
	            last = i+1;
	        }
	        i++;
	    }
	    
	    for(int i = 0; i < temp.size(); i++){
	        cout << temp[i];
	    }
	    
	    cout << endl;
	    
	    test--;
	}
	
	return 0;
}
