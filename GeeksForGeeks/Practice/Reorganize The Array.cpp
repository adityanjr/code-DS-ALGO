#include <iostream>
#include <vector>

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

void rearrangeVector(vector<int>& temp){
    int n = temp.size();
    
    for(int i = 0; i < n; i++){
        while(temp[i] != -1 && temp[i] < n && temp[i] != i){
            if(temp[i] == temp[temp[i]]){
                break;
            }
            swap(temp[i], temp[temp[i]]);
        }
    }
}

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    rearrangeVector(temp);
	    printVector(temp);
	    cout << endl;
	}
	
	return 0;
}
