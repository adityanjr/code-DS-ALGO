#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMin(string s, char c, int start, int end){
    int ans = -1;
    while(start <= end){
        if(s[start] > c){
            if(ans == -1){
                ans = start;
            }
            else if(s[ans] > s[start]){
                ans = start;
            }
        }
        start++;
    }
    
    return ans;
}

void swap(char& c, char& d){
    char temp = c;
    c = d;
    d = temp;
}

void make(string& s, int ind){
    int n = s.size();
    
    int index = findMin(s, s[ind], ind+1, n/2-1);
    swap(s[ind], s[index]);
    swap(s[n-ind-1], s[n-index-1]);
    
    vector<int> temp;
    
    for(int i = ind+1; i <= n/2-1; i++){
        temp.push_back(s[i]-'0');
    }
    
    sort(temp.begin(), temp.end());
    
    // for(int i = 0; i < temp.size(); i++){
    //     cout << temp[i] << " ";
    // }
    
    // cout << endl;
    // cout << "ind+1 : " << ind+1 << " , n/2 - 1 : " << (n/2 - 1) << endl;
    
    for(int i = ind+1; i <= n/2-1; i++){
        // cout << i << ", " << temp[i-ind-1] << endl;
        s[i] = (temp[i-ind-1]+'0');
        s[n-i-1] = (temp[i-ind-1]+'0');
    }
}

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string s;
	    cin >> s;
	    
	    int n = s.size(), ind = s.size()/2 - 1;
	    
	    bool found = false;
	    
	    for(int i = n/2-1; i >= 0; i--){
	        if(s[i] < s[ind]){
	            make(s, i);
	            found = true;
	            break;
	        }
	        else if(s[i] > s[ind]){
	            ind = i;
	        }
	    }
	    
	    if(found){
	        cout << s;
	    }
	    else{
	        cout << "-1";
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
