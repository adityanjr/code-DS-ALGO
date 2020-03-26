#include <iostream>
#include <vector>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, k, i = 0, j = 0, sum = 0;
	    cin >> n >> k;
	    
	    bool found = false;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    while(i < n || j < n){
	        if(sum == k){
	            found = true;
	            break;
	        }
	        else if(sum > k){
	            sum -= temp[j];
	            j++;
	        }
	        else{
	            if(i == n){
	                break;
	            }
	            sum += temp[i];
	            i++;
	        }
	    }
	    
	    if(!found){
	        cout << "-1";
	    }
	    else{
	        cout << j+1 << " " << i;
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
