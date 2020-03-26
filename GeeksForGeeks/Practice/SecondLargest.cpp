#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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
        
        priority_queue<int, vector<int>, greater<int> > q;
        q.push(temp[0]);
        q.push(temp[1]);
        
        for(int i = 2; i < n; i++){
            if(q.top() < temp[i]){
                q.pop();
                q.push(temp[i]);
            }
        }
        
        cout << q.top() << endl;
    }
    
	return 0;
}
