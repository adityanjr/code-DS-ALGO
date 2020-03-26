#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n1, n2;
	    cin >> n1 >> n2;
	    
	    map<int, bool> m;
	    
	    vector<int> temp1(n1);
	    vector<int> temp2(n2);
	    
	    for(int i = 0; i < n1; i++){
	        cin >> temp1[i];
	    }
	    
	    for(int i = 0; i < n2; i++){
	        cin >> temp2[i];
	        m[temp2[i]] = true;
	    }
	    
	    for(int i = 0; i < n1; i++){
	        if(m.find(temp1[i]) == m.end()){
                cout << temp1[i] << " ";
	        }
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
