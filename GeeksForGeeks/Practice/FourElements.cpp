#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, key, ans = 0;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    cin >> key;
	    
	    sort(temp.begin(), temp.end());
	    
	    for(int i = 0; i < n; i++){
	        for(int j = i+1; j < n; j++){
	            int k = j + 1, l = n - 1;
	            while(k < l){
	                int sum = temp[i] + temp[j] + temp[k] + temp[l];
	                if(sum == key){
	                    ans = 1;
	                    goto ANS;
	                }
	                else if(sum < key){
	                    k++;
	                }
	                else{
	                    l--;
	                }
	            }
	        }
	    }
	    
	    ANS:cout << ans << endl;
	}
	
	return 0;
}
