#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

// struct temp{
//     int index;
//     int val;
// };

// struct comp{
//     bool operator() (temp a, temp b){
//         if(a.val < b.val){
//             return true;
//         }
//         else if(a.val == b.val){
//             if(a.index < b.index){
//                 return true;
//             }
//         }
//         return false;
//     }  
// };

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, k;
	    cin >> n;
	    
	   // vector<temp> vec(n);
	    
	   // for(int i = 0; i < n; i++){
	   //     int num;
	   //     cin >> num;
	        
	   //     temp t;
	   //     t.val = num;
	   //     t.index = i;
	        
	   //     vec[i] = t;
	   // }
	    
	    map<int, vector<int> > m;
	    
	    for(int i = 0; i < n; i++){
	        int num;
	        cin >> num;
	        
	        m[num].push_back(i);
	    }
	    
	    cin >> k;
	    
	    map<int, vector<int> > :: iterator it = m.end();
	    it--;
	    
	    while(k){
	        vector<int> t = it->second;
	        for(int i = 0; i < t.size(); i++){
	            cout << t[i] << " ";
	        }
	        
	        it--;
	        k--;
	    }
	    
	    
	   // priority_queue<temp, vector<temp>, comp> q;
	    
	   // for(int i = 0; i < k; i++){
	   //     temp t;
	   //     t.val = vec[i].val;
	   //     t.index = i;
	   //     q.push(t);
	   // }
	    
	   // for(int i = k; i < n; i++){
	   //     temp t = q.top();
	   //     if(t.val < vec[i].val){
	   //         q.pop();
	   //         q.push(vec[i]);
	   //     }
	   // }
	    
	   // vector<int> ans(k);
	    
	   // while(!q.empty()){
	   //     ans[q.size()-1] = (q.top()).index;
	   //     q.pop();
	   // }
	    
	   // for(int i = 0; i < k; i++){
	   //     cout << ans[i] << " ";
	   // }
	    
	    cout << endl;
	}
	
	return 0;
}
