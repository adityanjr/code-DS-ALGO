#include <iostream>
#include <vector>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n1, n2, n3;
	    cin >> n1 >> n2 >> n3;
	    
	    vector<int> temp1(n1), temp2(n2), temp3(n3);
	    
	    for(int i = 0; i < n1; i++){
	        cin >> temp1[i];
	    }
	    
	    for(int i = 0; i < n2; i++){
	        cin >> temp2[i];
	    }
	    
	    for(int i = 0; i < n3; i++){
	        cin >> temp3[i];
	    }
	    
	    int i = 0, j = 0, k = 0, count = 0;
	    
	    while(i < n1 && j < n2 && k < n3){
	        if(temp1[i] == temp2[j] && temp1[i] == temp3[k]){
	            cout << temp1[i] << " ";
	            i++;
	            j++;
	            k++;
	            count = 1;
	        }
	        else{
	            if(temp1[i] <= temp2[j] && temp1[i] <= temp3[k]){
	                i++;
	            }
	            else if(temp2[j] <= temp3[k] && temp2[j] <= temp1[i]){
	                j++;
	            }
	            else{
	                k++;
	            }
	        }
	    }
	    
	    if(!count){
	        cout << "-1";
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
