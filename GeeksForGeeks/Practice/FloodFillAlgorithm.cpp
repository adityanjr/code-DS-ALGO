#include <iostream>
#include <vector>

using namespace std;

void make(vector<vector<int> >& temp, vector<vector<bool> >& visited, int x, int y, int k, int curr){
    if(x >= temp.size() || x < 0){
        return;
    }
    if(y >= temp[0].size() || y < 0){
        return;
    }
    
    if(temp[x][y] != curr){
        return;
    }
    if(visited[x][y]){
        return;
    }
    
    visited[x][y] = true;
    temp[x][y] = k;
    
    // make(temp, visited, x-1, y-1, k, curr);
    make(temp, visited, x-1, y, k, curr);
    // make(temp, visited, x-1, y+1, k, curr);
    make(temp, visited, x, y-1, k, curr);
    make(temp, visited, x, y+1, k, curr);
    // make(temp, visited, x+1, y-1, k, curr);
    make(temp, visited, x+1, y, k, curr);
    // make(temp, visited, x+1, y+1, k, curr);
}

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, m, x, y, k;
	    cin >> n >> m;
	    
	    vector<vector<int> > temp(n, vector<int>(m));
	    
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < m; j++){
	            cin >> temp[i][j];
	        }
	    }
	    
	    vector<vector<bool> > visited(n, vector<bool>(m, false));
	    
	    cin >> x >> y >> k;
	    
	    make(temp, visited, x, y, k, temp[x][y]);
	    
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < m; j++){
	            cout << temp[i][j] << " ";
	        }
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
