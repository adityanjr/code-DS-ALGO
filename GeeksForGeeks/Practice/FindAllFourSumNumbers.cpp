#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int n, kk;
	    cin >> n >> kk;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    sort(temp.begin(), temp.end());
	    
	    vector<vector<int> > sol;
	    
	    int i = 0;
	    
	    while(i < n){
	        int j = i+1;
	        while(j < n){
	            int l = n-1, k = j+1;
	            while(k < l){
	                int sum = temp[i] + temp[j] + temp[k] + temp[l];
	                if(sum == kk){
	                    vector<int> t(4);
	                    t[0] = temp[i];
	                    t[1] = temp[j];
	                    t[2] = temp[k];
	                    t[3] = temp[l];
	                    sol.push_back(t);
	                    while(temp[k] == temp[k+1] && k+1 < n){
	                        k++;
	                    }
	                    k++;
	                }
	                else if(sum < kk){
	                    k++;
	                }
	                else{
	                    l--;
	                }
	            }
	            while(temp[j] == temp[j+1] && j+1 < n){
	                j++;
	            }
	            j++;
	        }
	        while(temp[i] == temp[i+1] && i+1 < n){
                i++;
            }
	        i++;
	    }
	    
	    if(sol.size() == 0){
	        cout << -1;
	    }
	    else{
	        for(int i = 0; i < sol.size(); i++){
	            vector<int> temp = sol[i];
	            for(int j = 0; j < temp.size(); j++){
	                cout << temp[j] << " ";
	            }
	            cout << "$";
	        }
	    }
	    cout << endl;
	    
	    test--;
	}
	
	return 0;
}
