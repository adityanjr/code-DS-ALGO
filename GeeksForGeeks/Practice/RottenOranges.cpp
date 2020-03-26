#include <iostream>
#include <vector>
#include <queue>

struct temp{
    int x, y, time;
};

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, m, count = 0;
	    cin >> n >> m;
	    
	    vector<vector<int> > vec(n, vector<int>(m));
	    vector<vector<bool> > visited(n, vector<bool>(m, false));
	    
	    queue<temp> q;
	    
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < m; j++){
	            cin >> vec[i][j];
	            if(vec[i][j] == 2){
	                temp t;
	                t.x = i;
	                t.y = j;
	                t.time = 0;
	                q.push(t);
	                visited[i][j] = true;
	            }
	        }
	    }
	    
	   // for(int i = 0; i < n; i++){
	   //     for(int j = 0; j < m; j++){
	   //         cout << vec[i][j] << " ";
	   //     }
	   //     cout << endl;
	   // }
	    
	   // cout << endl;
	    
	    while(!q.empty()){
	        temp t = q.front();
	        int x = t.x, y = t.y, time = t.time;
	        if(x-1 >= 0){
	            if(!visited[x-1][y] && vec[x-1][y] == 1){
	                temp t1;
	                t1.x = x-1;
	                t1.y = y;
	                t1.time = time+1;
	                q.push(t1);
	                visited[x-1][y] = true;
	            }
	        }
	        if(x+1 < n){
	            if(!visited[x+1][y] && vec[x+1][y] == 1){
	                temp t1;
	                t1.x = x+1;
	                t1.y = y;
	                t1.time = time+1;
	                q.push(t1);
	                visited[x+1][y] = true;
	            }
	        }
	        if(y-1 >= 0){
	            if(!visited[x][y-1] && vec[x][y-1] == 1){
	                temp t1;
	                t1.x = x;
	                t1.y = y-1;
	                t1.time = time+1;
	                q.push(t1);
	                visited[x][y-1] = true;
	            }
	        }
	        if(y+1 < m){
	            if(!visited[x][y+1] && vec[x][y+1] == 1){
	                temp t1;
	                t1.x = x;
	                t1.y = y+1;
	                t1.time = time+1;
	                q.push(t1);
	                visited[x][y+1] = true;
	            }
	        }
	        count = max(count, time);
	        q.pop();
	    }
	    
	   // for(int i = 0; i < n; i++){
	   //     for(int j = 0; j < m; j++){
	   //         cout << visited[i][j] << " ";
	   //     }
	   //     cout << endl;
	   // }
	    
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < m; j++){
	            if(!visited[i][j] && vec[i][j] == 1){
	               // cout << count << endl;
	               // cout << i << " " << j << endl;
	                count = -1;
	                goto ANS;
	            }
	        }
	    }
	    
	    ANS:cout << count << endl;
	   // cout << endl;
	}
	
	return 0;
}
