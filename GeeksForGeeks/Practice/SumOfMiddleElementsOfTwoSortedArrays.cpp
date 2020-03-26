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
	    
	    vector<int> temp1(n), temp2(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp1[i];
	    }
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp2[i];
	    }
	    
	    int i = 0, j = 0, count = 0, sum = 0;
	    
	    while(i < n && j < n && count < n-1){
	        if(temp1[i] < temp2[j]){
	            i++;
	        }
	        else{
	            j++;
	        }
	        count++;
	    }
	    
	    if(temp1[i] < temp2[j]){
	        sum = temp1[i];
	        i++;
	    }
	    else{
	        sum = temp2[j];
	        j++;
	    }
	    
	    if(i < n && j < n){
	        sum += min(temp1[i], temp2[j]);
	    }
	    else if(i < n){
	        sum += temp1[i];
	    }
	    else{
	        sum += temp2[j];
	    }
	    
	    cout << sum << endl;
	}
	
	return 0;
}
