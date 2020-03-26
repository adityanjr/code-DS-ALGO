#include<iostream>
#include<vector>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, ans = 1;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    // DP solution
	    vector<int> greater(n, 1);
	    vector<int> smaller(n, 1);
	    
	    for(int i = 1; i < n; i++){
	        for(int j = i-1; j >= 0; j--){
	            if(temp[i] > temp[j]){
	                greater[i] = max(greater[i], smaller[j]+1);
	            }
	            else if(temp[i] < temp[j]){
	                smaller[i] = max(smaller[i], greater[j]+1);
	            }
	        }
	        
	        ans = max(greater[i], smaller[i]);
	    }
	    
	   // below is the code for continuous sub-sequence
	   // int flag = -1, ans = 1, tempAns = 1;
	   // // -1 for start, 1 for last greater, 0 for last smaller
	    
	   // for(int i = 1; i < n; i++){
	   //     if(temp[i] > temp[i-1]){
	   //         if(flag == -1 || flag == 0){
	   //             flag = 1;
	   //             tempAns++;
	   //         }
	   //         else{
	   //             tempAns = 2;
	   //         }
	   //     }
	   //     else if(temp[i] < temp[i-1]){
	   //         if(flag == -1 || flag == 1){
	   //             flag = 0;
	   //             tempAns++;
	   //         }
	   //         else{
	   //             tempAns = 2;
	   //         }
	   //     }
	   //     else{
	   //         tempAns = 1;
	   //         flag = -1;
	   //     }
	   //     ans = max(ans, tempAns);
	   // }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
