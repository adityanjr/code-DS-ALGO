// http://www.practice.geeksforgeeks.org/problem-page.php?pid=719

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int getPart(vector<int> temp, int curr){
    for(int i = curr+1; i < temp.size(); i++){
        if(temp[i] > temp[curr]){
            return i;
        }
    }
    
    return -1;
}

bool check(vector<int> temp, int curr, int end, int mini, int maxi){
    if(curr >= end){
        return true;
    }
    
    for(int i = curr; i <= end; i++){
        if(!(temp[i] > mini && temp[i] < maxi)){
            return false;
        }
    }

    int part = getPart(temp, curr);   
    
    if(part == -1){
        return check(temp, curr+1, end, mini, temp[curr]);
    }

    return check(temp, curr+1, part-1, mini, temp[curr]) && check(temp, part, end, temp[curr], maxi);
}

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int n;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    int ans = 0;
	    
	    if(check(temp, 0, temp.size()-1, INT_MIN, INT_MAX)){
	        ans = 1;
	    }
	    
	    cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
