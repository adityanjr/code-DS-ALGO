#include <iostream>
#include <map>

struct temp{
    int a, b;
};

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string s1, s2;
	    cin >> s1 >> s2;
	    
	    map<char, temp> m;
	    
	    for(int i = 0; i < s1.size(); i++){
	        if(m.find(s1[i]) == m.end()){
	            temp t1;
	            t1.a = 1;
	            t1.b = 0;
	            m[s1[i]] = t1;
	        }
	        else{
	            m[s1[i]].a++;
	        }
	    }
	    
	    for(int i = 0; i < s2.size(); i++){
	        if(m.find(s2[i]) == m.end()){
	            temp t1;
	            t1.a = 0;
	            t1.b = 1;
	            m[s2[i]] = t1;
	        }
	        else{
	            m[s2[i]].b++;
	        }
	    }
	    
	    map<char, temp> :: iterator it = m.begin();
	    
	    while(it != m.end()){
	        if(!(it->second).a || !(it->second).b){
	            cout << it->first;
	        }
	        it++;
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
