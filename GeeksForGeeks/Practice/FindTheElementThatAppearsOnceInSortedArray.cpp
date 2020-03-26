#include <iostream>
#include <vector>

using namespace std;

int check(vector<int> temp, int i, int n){
    while(i < n){
        if(temp[i] == temp[i+1]){
            while(temp[i] == temp[i+1]){
                i++;
            }
        }
        else{
            return temp[i];
        }
        i++;
    }
    
    return temp[n];
}

int main() {
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
	    
	    cout << check(temp, 0, n-1) << endl;
	}
	
	return 0;
}
