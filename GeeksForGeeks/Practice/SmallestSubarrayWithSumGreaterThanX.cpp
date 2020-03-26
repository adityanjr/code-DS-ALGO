#include <iostream>
#include <vector>

using namespace std;

int mini(int x, int y){
    if(x > y){
        return y;
    }
    return x;
}

int main() {
	//code
	int test;
	cin >> test;
	
	while(test){
	    int n, x;
	    cin >> n >> x;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    int i = 0, j = 0, ans = n+1;;
	    int sum = 0;
	    
	    LOOP:while((i < n) && (j < n)){
	        if(j > i){
	            sum = sum - temp[j];
	            j++;
	            goto LOOP;
	        }
	        if(sum <= x){
	            sum = sum + temp[i];           
	            i++;
	        }
	        else{
	            ans = mini(ans, i-j);
	            sum = sum - temp[j]; 
	            j++;
	        }
	    }
	    
	    while((sum > x) && (i <= n) && (j < n)){
	        sum = sum- temp[j];
	        ans = mini(ans, i-j);
	        j++;
	    }
	    
	    cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
