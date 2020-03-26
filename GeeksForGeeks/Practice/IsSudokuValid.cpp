#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool valid(vector<vector<int> >& temp){
    // row validation
    for(int i = 0; i < 9; i++){
        map<int, bool> m;
        for(int j = 0; j < 9; j++){
            if(temp[i][j] != 0){
                if(m.find(temp[i][j]) == m.end()){
                    m[temp[i][j]] = true;
                }
                else{
                    return false;
                }
            }
        }
    }
    
    // column validation
    for(int i = 0; i < 9; i++){
        map<int, bool> m;
        for(int j = 0; j < 9; j++){
            if(temp[j][i] != 0){
                if(m.find(temp[j][i]) == m.end()){
                    m[temp[j][i]] = true;
                }
                else{
                    return false;
                }
            }
        }
    }
    
    // box validation
    for(int i = 0; i < 9; i+=3){
        for(int k = 0; k < 3; k++){
            map<int, bool> m;
            for(int j = k*3; j < (k+1)*3; j++){
                if(temp[j][i] != 0){
                    if(m.find(temp[j][i]) == m.end()){
                        m[temp[j][i]] = true;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
    }
    
    return true;
}

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    vector<vector<int> > temp(9, vector<int>(9));
	    
	    for(int i = 0; i < 9; i++){
	        for(int j = 0; j < 9; j++){
	            cin >> temp[i][j];
	        }
	    }
	    
	    cout << valid(temp) << endl;
	}
	
	return 0;
}
