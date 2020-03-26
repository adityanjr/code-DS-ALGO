#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int floorFn(vector<int>& temp, int x){
    int start = 0, end = temp.size()-1, ans = -1;
    
    while(start <= end){
        int mid = start + (end-start)/2;
        if(temp[end] <= x){
            ans = max(ans, end);
        }        
        if(temp[mid] == x){
            ans = max(ans, mid);
            end = mid-1;
        }
        else if(temp[mid] > x){
            end = mid-1;
        }
        else{
            if(ans != -1){
                if(temp[mid] > temp[ans]){
                    ans = mid;
                }
                else if(temp[mid] == temp[ans]){
                    ans = max(ans, mid);
                }
            }
            else{
                ans = mid;
            }
            start = mid+1;
        }
    }
    
    return ans;
}

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int n, x;
	    cin >> n >> x;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    cout << floorFn(temp, x) << endl;
	    
	    test--;
	}
	
	return 0;
}
