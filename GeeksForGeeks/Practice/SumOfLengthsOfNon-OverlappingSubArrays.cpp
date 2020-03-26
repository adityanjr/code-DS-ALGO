#include <iostream>
#include <vector>

using namespace std;

int ls(vector<int>& temp, int start, int end, int key){
    while(start <= end){
        if(temp[start] == key){
            return start;
        }
        start++;
    }
    
    return -1;
}

int check(vector<int>& temp, int ind, int& last){
    int ans = 1, num = temp[ind], i = ind-1, j = ind+1, n = temp.size(), tempLast = last;
    
    while(i > last || j < n){
        if(i > last && j < n){
            if(temp[i] > num && temp[j] > num){
                last = tempLast;
                return ans;
            }
            else if(temp[i] <= num && temp[j] <= num){
                ans += 2;
                tempLast = j;
                i--;
                j++;
            }
            else if(temp[i] <= num){
                ans++;
                j = n;
                i--;
            }
            else{
                tempLast = j;
                ans++;
                i = -1;
                j++;
            }
        }
        else if(i > last){
            if(temp[i] > num){
                last = tempLast;
                return ans;
            }
            ans++;
            i--;
        }
        else{
            if(temp[j] > num){
                last = tempLast;
                return ans;
            }
            tempLast = j;
            ans++;
            j++;
        }
    }

    return ans;
}

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, k;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    cin >> k;
	    
	    int last = -1, ans = 0;
	    
	    int index = ls(temp, 0, n-1, k);
	    
	    while(index != -1){
	        ans += check(temp, index, last);
	        last = max(last, index);
	        index = ls(temp, index+1, n-1, k);
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
