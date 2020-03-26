#include <iostream>
#include <map>

using namespace std;

void insertInMap(map<string, int>& m, string s){
    if(m.find(s) == m.end()){
        m[s] = 1;
    }
    else{
        m[s]++;
    }
}

void checkAns(map<string, int>& m, string s, int& maxi, string& ans){
    if(m[s] > maxi){
        maxi = m[s];
        ans = s;
    }
    else if(m[s] == maxi){
        if(s < ans){
            maxi = m[s];
            ans = s;
        }
    }
}

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, maxi = 0;
	    cin >> n;
	    
	    string ans = "";
	    
	    map<string, int> m;
	    
	    for(int i = 0; i < n; i++){
	        string s;
	        cin >> s;
	        
	        insertInMap(m, s);
	        checkAns(m, s, maxi, ans);
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
