#include <iostream>
#include <map>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test){
	    int n, m, k;
	    cin >> n >> m >> k;
	    
	    map<int, int> a, b;
	    
	    for(int i = 0; i < n; i++){
	        int num;
	        cin >> num;
	        
	        if(a.find(num) == a.end()){
	            a[num] = 1;
	        }
	        else{
	            a[num]++;
	        }
	    }
	    
	    for(int i = 0; i < m; i++){
	        int num;
	        cin >> num;
	        
	        if(b.find(num) == b.end()){
	            b[num] = 1;
	        }
	        else{
	            b[num]++;
	        }
	    }
	    
	    map<int, int> :: iterator it = a.begin();
	    
	    int count = 0;
	    
	    while(it != a.end()){
	        map<int, int> :: iterator itt = b.find(k-(it->first));
	        if(itt != b.end()){
	            int temp = (it->second)*(itt->second);
	            while(temp){
    	            if(count){
    	                cout << ", ";
    	            }
    	            cout << it->first << " " << itt->first;
	                temp--;
	            }
	            count++;
	        }
	        it++;
	    }
	    
	    if(!count){
	        cout << "-1";
	    }
	    
	    cout << endl;
	    
	    test--;
	}
	
	return 0;
}
