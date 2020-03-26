#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int n;
	    cin >> n;
	    
	    vector<int> A(n);
	    
	    int ans = n+1;
	    
	    vector<map<int, int> > temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> A[i];
	    }
	    
	    for(int i = 1; i < n; i++){
	        for(int j = i-1; j >= 0; j--){
	            int diff = A[i] - A[j];
	            if(temp[i].find(diff) == temp[i].end()){
	                temp[i][diff] = 1;
	                if(temp[j].find(diff) != temp[j].end()){
    	                temp[i][diff] = temp[j][diff] + 1;
    	            }
	            }
	            else{
	                temp[i][diff]++;
	            }
	            ans++;
	            if(temp[j].find(diff) != temp[j].end()){
	                ans = ans + temp[j][diff];
	            }
	        }
	    }
	    
	    cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
