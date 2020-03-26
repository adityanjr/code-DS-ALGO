#include <iostream>

using namespace std;

void swap(char& a, char& b){
    char temp = a;
    a = b;
    b = temp;
}

void reverse(string& s, int j, int k){
    for(int i = j; i < (j+k)/2; i++){
        swap(s[i], s[k-(i-j)-1]);
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
        
        int i = 0, n = s.size();
        
        while(i < n){
            int j = i;
            
            while(s[j] != '.' && j < n){
                j++;
            }
            
            reverse(s, i, j);
            
            i = j;
            i++;
        }
	    
	    cout << s << endl;
	}
	
	return 0;
}
