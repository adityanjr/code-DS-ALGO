#include <iostream>
#include <map>

using namespace std;

bool checkEqual(map<char, int>& m1, map<char, int>& m2){
    map<char, int> :: iterator it = m2.begin();
    
    while(it != m2.end()){
        if(m1.find(it->first) == m1.end()){
            return false;
        }
        else if(m1[it->first] < it->second){
            return false;
        }
        it++;
    }
    
    return true;
}

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string s1, s2;
	    cin >> s1 >> s2;
	    
	    map<char, int> m1, m2;
	    
	    for(int i = 0; i < s2.size(); i++){
	        if(m2.find(s2[i]) == m2.end()){
	            m2[s2[i]] = 1;
	        }
	        else{
	            m2[s2[i]]++;
	        }
	    }
	    
	    int i = 0, j = 0, ans = -1, temp = -1, n = s1.size(), s = -1, e = -1, ts = -1, te = -1;
	    
	    while(i < n){
	        if(m1.find(s1[i]) == m1.end()){
	            m1[s1[i]] = 1;
	        }
	        else{
	            m1[s1[i]]++;
	        }
	        
	        if(checkEqual(m1, m2)){
	            while(j < i && m1[s1[j]] > m2[s1[j]]){
	                m1[s1[j]]--;
	                j++;
	            }
	            ts = j;
	            te = i;
	            temp = i-j+1;
	            if(temp != -1){
        	        if(ans == -1){
        	            ans = temp;
        	            s = ts;
        	            e = te;
        	        }
        	        else if(temp < ans){
        	            ans = temp;
        	            s = ts;
        	            e = te;
        	        }
    	        }
	        }
	        i++;
	    }
	    
	    if(ans == -1){
	        cout << "-1";
	    }
	    else{
	        for(int i = s; i <= e; i++){
	            cout << s1[i];
	        }
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
