#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

bool swapped(vector<int> temp, int index){
    if(temp[index] < 0 || temp[index] > temp.size()){
        return false;
    }
    if(temp[index] == index+1){
        return false;
    }
    if(temp[index] == temp[temp[index]-1]){
        return false;
    }
    return true;
}

int main() {
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
	    
	    for(int i = 0; i < n; i++){
	        while(swapped(temp, i)){
	            swap(temp[i], temp[temp[i]-1]);
	        }
	    }
	    
	    for(int i = 0; i < n; i++){
	        if(temp[i] != i+1){
	            break;
	        }
	        ans++;
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
