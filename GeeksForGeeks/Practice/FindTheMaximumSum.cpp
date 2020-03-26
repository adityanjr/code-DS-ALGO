#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long int multiply(vector<int>& temp, int start, int end){
    int i = start, n = end;
    
    long int ans = 0, num = pow(10, 9) + 7;
    
    while(i < n){
        long int t = temp[i];
        if(i+1 < n){
            t = t*temp[i+1];
        }
        
        t = t%num;
        ans += t;
        ans = ans%num;
        
        i += 2;
    }
    
    return ans;
}

void count(vector<int>& temp, int& pCount, int& nCount){
    for(int i = 0; i < temp.size(); i++){
        if(temp[i] <= 0){
            nCount++;
        }
        else{
            pCount++;
        }
    }
}

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, pCount = 0, nCount = 0;;
	    cin >> n;
	    
	    long int ans = 0, mult = pow(10, 9) + 7;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    sort(temp.begin(), temp.end());
	    count(temp, pCount, nCount);
	    
	   // cout << "pCount : " << pCount << ", " << "nCount : " << nCount << endl;
	    
	    if((pCount + nCount)%2){
	        
	        if(pCount%2 == 0){
	            ans = (multiply(temp, 0, nCount-1)%mult + temp[nCount-1]%mult + multiply(temp, nCount, n)%mult)%mult;
	        }
	        else{
	            ans = (multiply(temp, 0, nCount)%mult + temp[nCount]%mult + multiply(temp, nCount+1, n)%mult)%mult;
	        }
	    }
	    else{
	        ans = multiply(temp, 0, n);
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
