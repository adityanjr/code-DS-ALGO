#include <iostream>
#include <map>
#include <utility>
#include <cmath>

using namespace std;

int makeAn(string& s1, string& s2, int n){
    map<int, pair<int, int> > m;
    
    for(int i = 0; i < n; i++){
        if(m.find(s1[i]) == m.end()){
            m[s1[i]] = pair<int, int> (1, 0);
        }
        else{
            m[s1[i]].first++;
        }
        if(m.find(s2[i]) == m.end()){
            m[s2[i]] = pair<int, int> (0, 1);
        }
        else{
            m[s2[i]].second++;
        }
    }
    
    map<int, pair<int, int> > :: iterator it = m.begin();
    
    int ans = 0;
    
    while(it != m.end()){
        ans += abs((it->second).first - (it->second).second);
        it++;
    }
    
    return ans/2;
}

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n;
	    cin >> n;
	    
	    string s1, s2;
	    cin >> s1 >> s2;
	    
	    cout << makeAn(s1, s2, n) << endl;
	}
	
	return 0;
}
