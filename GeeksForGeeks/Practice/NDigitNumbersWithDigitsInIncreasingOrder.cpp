#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct temp{
    long long int num;
    int last;
    int len;
};

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n;
	    cin >> n;
	    
	    queue<temp> q;
	    
	    for(int i = 1; i <= 9; i++){
	        temp t;
	        t.num = i;
	        t.last = i;
	        t.len = 1;
	        q.push(t);
	    }
	    
	    while(!q.empty()){
	        temp t = q.front();
	        if(t.len == n){
	            cout << t.num << " ";
	        }
	        else if(t.len < n){
	            for(int i = t.last+1; i <= 9; i++){
	                temp t1;
	                t1.num = stoll(to_string(t.num) + to_string(i));
	                t1.last = i;
	                t1.len = t.len + 1;
	                q.push(t1);
	            }
	        }
	        q.pop();
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
