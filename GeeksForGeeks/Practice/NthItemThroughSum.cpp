#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, m, k;
	    cin >> n >> m;
	    
	    vector<int> A(n);
	    vector<int> B(m);
	    
	    for(int i = 0; i < n; i++){
	        cin >> A[i];
	    }
	    
	    for(int i = 0; i < m; i++){
	        cin >> B[i];
	    }
	    
	    cin >> k;
	    
	    set<int> s;
	    
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < m; j++){
	            int sum = A[i] + B[j];
	            if(s.find(sum) == s.end()){
	                s.insert(sum);
	            }
	        }
	    }
	    
	    set<int> :: iterator itt = s.begin();
	    
	   // while(itt != s.end()){
	   //     cout << *itt << " ";
	   //     itt++;
	   // }
	    
	    if(s.size() < k){
	        cout << "-1";
	    }
	    else{
	        set<int> :: iterator it = s.begin();
	        while(k-1){
	            it++;
	            k--;
	        }
	        cout << *it;
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
