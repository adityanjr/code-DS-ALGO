#include <iostream>
#include <map>
#include <queue>
#include <utility>

using namespace std;

struct temp{
    int x, y, moves;
};

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, x, y, tx, ty, ans = 1;
	    cin >> n >> x >> y >> tx >> ty;
	    
	    queue<temp> q;
	    map<pair<int, int>, bool> m;
	    
	    temp in;
	    in.x = x;
	    in.y = y;
	    in.moves = 0;
	    
	    q.push(in);
	    pair<int, int> p(x, y);
	    m[p] = true;
	    
	    while(!q.empty()){
	        temp t = q.front();
	        q.pop();
	        if(t.x == tx && t.y == ty){
	            ans = t.moves;
	            break;
	        }
	        int xx = t.x, yy = t.y, moves = t.moves;
	        if(xx-1 > 0 && yy+2 <= n){
	            temp t;
	            t.x = xx-1;
	            t.y = yy+2;
	            pair<int, int> p(t.x, t.y);
	            if(m.find(p) == m.end()){
	                m[p] = true;
    	            t.moves = moves+1;
    	            q.push(t);
	            }
	            
	        }
	        if(xx+1 <= n && yy+2 <= n){
	            temp t;
	            t.x = xx+1;
	            t.y = yy+2;
	            pair<int, int> p(t.x, t.y);
	            if(m.find(p) == m.end()){
	                m[p] = true;
    	            t.moves = moves+1;
    	            q.push(t);
	            }
	            
	        }
	        if(xx-1 > 0 && yy-2 > 0){
	            temp t;
	            t.x = xx-1;
	            t.y = yy-2;
	            pair<int, int> p(t.x, t.y);
	            if(m.find(p) == m.end()){
	                m[p] = true;
    	            t.moves = moves+1;
    	            q.push(t);
	            }
	            
	        }
	        if(xx+1 <= n && yy-2 > 0){
	            temp t;
	            t.x = xx+1;
	            t.y = yy-2;
	            pair<int, int> p(t.x, t.y);
	            if(m.find(p) == m.end()){
	                m[p] = true;
    	            t.moves = moves+1;
    	            q.push(t);
	            }
	            
	        }
	        if(xx+2 <= n && yy+1 <= n){
	            temp t;
	            t.x = xx+2;
	            t.y = yy+1;
	            pair<int, int> p(t.x, t.y);
	            if(m.find(p) == m.end()){
	                m[p] = true;
    	            t.moves = moves+1;
    	            q.push(t);
	            }
	            
	        }
	        if(xx+2 <= n && yy-1 > 0){
	            temp t;
	            t.x = xx+2;
	            t.y = yy-1;
	            pair<int, int> p(t.x, t.y);
	            if(m.find(p) == m.end()){
	                m[p] = true;
    	            t.moves = moves+1;
    	            q.push(t);
	            }
	            
	        }
	        if(xx-2 > 0 && yy+1 <= n){
	            temp t;
	            t.x = xx-2;
	            t.y = yy+1;
	            pair<int, int> p(t.x, t.y);
	            if(m.find(p) == m.end()){
	                m[p] = true;
    	            t.moves = moves+1;
    	            q.push(t);
	            }
	            
	        }
	        if(xx-2 > 0 && yy-1 > 0){
	            temp t;
	            t.x = xx-2;
	            t.y = yy-1;
	            pair<int, int> p(t.x, t.y);
	            if(m.find(p) == m.end()){
	                m[p] = true;
    	            t.moves = moves+1;
    	            q.push(t);
	            }
	            
	        }
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
