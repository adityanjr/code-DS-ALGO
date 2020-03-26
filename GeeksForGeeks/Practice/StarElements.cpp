#include <iostream>
#include <vector>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    vector<int> rmax(n, 0) ;
	    rmax[n-1] = 1;
	    
	    int maxi = temp[n-1], last = n-1;
	    bool super = true;
	    
	    for(int i = n-2; i >= 0; i--){
	        if(temp[i] > maxi){
	            rmax[i] = 1;
	            maxi = temp[i];
	            super = true;
	        }
	        else if(temp[i] == maxi){
	            super = false;
	        }
	    }
	    
	    for(int i = 0; i < n; i++){
	        if(rmax[i]){
	            last = min(last, i);
	            cout << temp[i] << " ";
	        }
	    }
	    
	    cout << endl;
	    
	    if(!super){
	        cout << "-1";
	    }
	    else{
	        cout << temp[last];
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
