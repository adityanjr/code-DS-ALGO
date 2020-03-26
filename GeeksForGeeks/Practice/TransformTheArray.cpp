#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void findNonZero(vector<int>& temp, int& i){
    while(i < temp.size() && temp[i] == 0){
        i++;
    }
}

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void convertArray(vector<int>& temp){
    int i = 0, j = 0, n = temp.size();
    
    while(i < n){
        if(temp[i] != 0){
            swap(temp[i], temp[j]);
            j++;
        }
        i++;
    }
}

void stackSol(vector<int>& temp){
    stack<int> st;
    
    for(int i = 0; i < temp.size(); i++){
        if(temp[i] != 0){
            if(st.empty()){
                st.push(temp[i]);
            }
            else{
                if(st.top() == temp[i]){
                    st.pop();
                    st.push(2*temp[i]);
                }
                else{
                    st.push(temp[i]);
                }
            }
        }
    }
    
    int curr = st.size(), t = st.size();
    
    while(curr > 0){
        temp[curr-1] = st.top();
        st.pop();
        curr--;
    }
    
    for(int i = t; i < temp.size(); i++){
        temp[i] = 0;
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
	    
	    stackSol(temp);
	    
	   // int j = 0;
	   // findNonZero(temp, j);
	    
	   // int i = j+1;
	    
	   // while(i < n){
	   //     if(temp[i] == 0){
	   //         i++;
	   //     }
	   //     else if(temp[i] == temp[j]){
	   //         temp[j] = 2*temp[j];
	   //         temp[i] = 0;
	   //         j++;
	   //         findNonZero(temp, j);
	   //         i = j+1;
	   //     }
	   //     else{
	   //         int t = i;
	   //         j = i;
	   //         i = t+1;
	   //     }
	   // }
	    
	   // convertArray(temp);
	    
	    for(int i = 0; i < n; i++){
	        cout << temp[i] << " ";
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
