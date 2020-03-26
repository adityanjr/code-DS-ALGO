#include <iostream>
#include <map>

class temp{
    public:
    int fir, sec;
        temp(){
            fir = 0;
            sec = 0;
        }
};

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n1, n2;
	    cin >> n1 >> n2;
	    
	    string ans = "Yes";
	    
	    map<int, temp> m;
	    
	    for(int i = 0; i < n1; i++){
	        int num;
	        cin >> num;
	        
	        if(m.find(num) == m.end()){
	            temp t;
	            m[num] = t;
	        }
	        m[num].fir++;
	    }
	    
	    for(int i = 0; i < n2; i++){
	        int num;
	        cin >> num;
	        
	        if(m.find(num) == m.end()){
	            temp t;
	            m[num] = t;
	        }
	        m[num].sec++;
	    }
	    
	    map<int, temp> :: iterator it = m.begin();
	    
	    while(it != m.end()){
	        if((it->second).sec > (it->second).fir){
	            ans = "No";
	            break;
	        }
	        
	        it++;
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
