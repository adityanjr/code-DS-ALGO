#include <iostream>
#include <map>

using namespace std;

struct temp{
    int first, second;
};

void insert(map<char, temp>& m, string s, bool first){
    int n = s.size();
    
    for(int i = 0; i < n; i++){
        if(m.find(s[i]) == m.end()){
              temp t;
              t.first = 0;
              t.second = 0;
              if(first){
                  t.first = 1;
              }
              else{
                  t.second = 1;
              }
              m[s[i]] = t;
        }
        else{
            if(first){
                m[s[i]].first++;   
            }
            else{
                m[s[i]].second++;
            }
            
        }
    }
}

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string a, b;
	    cin >> a >> b;
	    
	    map<char, temp> m;
	    insert(m, a, true);
	    insert(m, b, false);
	    
	    string ans = "";
	    
	    for(int i = 0; i < a.size(); i++){
	        if(m[a[i]].second == 0){
	            ans += a[i];
	        }
	    }
	    
	    for(int i = 0; i < b.size(); i++){
	        if(m[b[i]].first == 0){
	            ans += b[i];
	        }
	    }
	    
	    if(ans.size() == 0){
	        cout << "-1";
	    }
	    cout << ans << endl;
	    
	}
	
	return 0;
}
