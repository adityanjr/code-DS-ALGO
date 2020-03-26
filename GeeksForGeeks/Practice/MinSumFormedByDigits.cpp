// http://www.practice.geeksforgeeks.org/problem-page.php?pid=1530

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string rev(string a){
    int n = a.size();
    for(int i = 0; i < n/2; i++){
        char temp = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = temp;
    }
    
    return a;
}

string sum(string a, string b){
    string ans = "";
    
    if(a.size() == 0 && b.size() == 0){
        ans = "0";
    }
    else{
        int i = 0, aa = a.size(), bb = b.size();
        a = rev(a);
        b = rev(b);
        
        // cout << a << " " << b << endl;
        
        int carry = 0;
        
        while(i < aa && i < bb){
            int sum = a[i] - '0' + b[i] - '0';
            ans = ans + to_string((sum+carry)%10);
            carry = (sum+carry)/10;
            i++;
        }
        
        while(i < aa){
            int sum = a[i] - '0';
            ans = ans + to_string((sum+carry)%10);
            carry = (sum+carry)/10;
            i++;
        }
        
        while(i < bb){
            int sum = b[i] - '0';
            ans = ans + to_string((sum+carry)%10);
            carry = (sum+carry)/10;
            i++;
        }
        
        if(carry){
            ans = ans + to_string(carry);
        }   
    }
    
    return rev(ans);
}

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int n;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    sort(temp.begin(), temp.end());
	    
	    string a = "", b = "";
	    
	    for(int i = 0; i < n; i = i + 2){
	        a = a + to_string(temp[i]);
	    }
	    
	    for(int i = 1; i < n; i = i + 2){
	        b = b + to_string(temp[i]);
	    }
	    
	    //cout << a << " " << b << endl;
	    //cout << sum(a, b) << endl;
	    
	    string ans = sum(a, b);
	    int i = 0;
	    
	    while(ans[i] == '0'){
	        i++;
	    }
	    
	    if(i == ans.size()){
	        cout << "0";
	    }
	    else{
	        while(i < ans.size()){
	            cout << ans[i];
	            i++;
	        }
	    }
	    
	    cout << endl;
	    
	    test--;
	}
	
	return 0;
}
