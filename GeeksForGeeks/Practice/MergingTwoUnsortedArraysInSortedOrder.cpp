#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n1, n2;
	    cin >> n1 >> n2;
	    
	    vector<int> temp1(n1);
	    vector<int> temp2(n2);
	    
	    for(int i = 0; i < n1; i++){
	        cin >> temp1[i];
	    }
	    
	    for(int i = 0; i < n2; i++){
	        cin >> temp2[i];
	    }
	    
	    sort(temp1.begin(), temp1.end());
	    sort(temp2.begin(), temp2.end());
	    
	    vector<int> ans(n1+n2);
	    
	    int i = 0, j = 0, curr = 0;
	    
	    while(i < n1 && j < n2){
	        if(temp1[i] < temp2[j]){
	            ans[curr] = temp1[i];
	            i++;
	        }
	        else{
	            ans[curr] = temp2[j];
	            j++;
	        }
	        curr++;
	    }
	    
	    while(i < n1){
            ans[curr] = temp1[i];
            i++;
	        curr++;
	    }
	    
	    while(j < n2){
            ans[curr] = temp2[j];
            j++;
	        curr++;
	    }
	    
	    for(int i = 0; i < n1+n2; i++){
	        cout << ans[i] << " ";
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
