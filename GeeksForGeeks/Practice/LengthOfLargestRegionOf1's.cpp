#include <iostream>
#include <vector>

using namespace std;

int find(vector<vector<int> >& temp, vector<vector<bool> >& visited, int i, int j){
    if(i >= temp.size() || i < 0){
        return 0;
    }
    if(j >= temp[i].size() || j < 0){
        return 0;
    }
    if(visited[i][j]){
        return 0;
    }
    visited[i][j] = true;
    
    if(temp[i][j] == 1){
        return 1 + find(temp, visited, i-1, j-1) + find(temp, visited, i-1, j) + find(temp, visited, i-1, j+1) + 
        find(temp, visited, i, j-1) + find(temp, visited, i, j+1) + find(temp, visited, i+1, j-1) + find(temp, visited, i+1, j)
        + find(temp, visited, i+1, j+1);
    }
    
    return 0;
}

int main() {
	//code
	int test;
	cin >> test;
    
    while(test--){
        int n, m;
        cin >> n >> m;
        
        vector<vector<int> > temp(n, vector<int>(m));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> temp[i][j];
            }
        }
        
        vector<vector<bool> > visited(n, vector<bool>(m));
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans, find(temp, visited, i, j));
            }
        }
        
        cout << ans << endl;
    }
	
	return 0;
}
