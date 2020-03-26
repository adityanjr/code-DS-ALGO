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
	    
	    bool swapp = false;
	    
	    for(int i = s.size()-1; i >= 0; i--){
	        int mini = -1;
	        for(int j = i+1; j < s.size(); j++){
	            if(s[j] > s[i]){
	                if(mini == -1){
	                    mini = j;
	                }
	                else if(s[mini] > s[j]){
	                    mini = j;
	                }
	            }
	        }
	        if(mini != -1){
	            swap(s[i], s[mini]);
	            swapp = true;
	            break;
	        }
	    }
	    
	    
	    if(!swapp){
	        cout << "-1";
	    }
	    else{
	        cout << s;
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
