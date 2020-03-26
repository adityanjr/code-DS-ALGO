#include <iostream>
#include <vector>

using namespace std;

void search(vector<int> temp, int start, int end, int& ans, int k, bool first){
    while(start <= end){
        int mid = start + (end - start)/2;
        
        if(temp[mid] == k){
            if(first){
                if(ans != -1){
                    ans = min(ans, mid);
                }
                else{
                    ans = mid;
                }
                end = mid-1;
            }
            else{
                ans = max(ans, mid);
                start = mid+1;
            }
        }
        else if(temp[mid] > k){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
}

int main() {
	//code
	int test;
	cin >> test;
	
	while(test){
	    int n, k;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    cin >> k;
	    
	    int first = -1, last = -1;
	    
	    search(temp, 0, n-1, first, k, true);
	    search(temp, 0, n-1, last, k, false);
	    
	    cout << first << " ";
	    
	    if(last != -1){
	        cout << last;
	    }
	    
	    cout << endl;
	    
	    test--;
	}
	
	return 0;
}
