#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n;
	    cin >> n;
	    
	    vector<vector<int> > temp(n, vector<int>(n));
	    
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < n; j++){
	            cin >> temp[i][j];
	        }
	    }
	    
	    for(int i = 0; i < n; i++){
	        for(int j = i; j < n; j++){
	            swap(temp[i][j], temp[j][i]);
	        }
	    }
	    
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < n; j++){
	            cout << temp[i][j] << " ";
	        }
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
