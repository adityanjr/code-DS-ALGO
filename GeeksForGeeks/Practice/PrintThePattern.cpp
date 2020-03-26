#include <iostream>

using namespace std;

void print(int start, int dash, int count, int end){
    if(count == 0){
        return;
    }
    
    for(int i = 0; i < dash; i++){
        cout << "-";
    }
    
    cout << start;
    
    for(int i = start+1; i < start+count; i++){
        cout << "*" << i;    
    }
    
    for(int i = end-count+1; i <= end; i++){
        cout << "*" << i;
    }
    
    cout << endl;
    
    print(start+count, dash+2, count-1, end-count);
}

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n;
	    cin >> n;
	    
	    print(1, 0, n, n*(n+1));
	}
	
	return 0;
}
