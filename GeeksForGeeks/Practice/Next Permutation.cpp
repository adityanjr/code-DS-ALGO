#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<int>& temp){
    for(int i = 0; i < temp.size(); i++){
        cout << temp[i] << " ";
    }
}

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int getMinIndex(vector<int>& temp, int num, int start, int end){
    int ans = start;
    while(start < end){
        if(temp[ans] > temp[start] && temp[start] > num){
            ans = start;
        }
        start++;
    }
    
    return ans;
}

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, found = 0;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    for(int i = n-1; i > 0; i--){
	        if(temp[i] > temp[i-1]){
	            found = 1;
	            int minIndex = getMinIndex(temp, temp[i-1], i, n);
	            swap(temp[minIndex], temp[i-1]);
	            sort(temp.begin()+i, temp.end());
	            break;
	        }
	    }
	    
	    if(!found){
	        sort(temp.begin(), temp.end());
	    }
	    
	    printVector(temp);
	    cout << endl;
	}
	
	return 0;
}
