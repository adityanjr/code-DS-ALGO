#include <iostream>
#include <stack>
#include <map>

using namespace std;

bool check(stack<bool> st, char c){
    bool pos = true;
    
    if(c == '-'){
        pos = false;
    }
    
    if(st.empty()){
        return pos;
    }
    else if(!st.top()){
        return !pos;
    }
    
    return pos;
}

void insertInMap(map<char, int>& m, char c, stack<bool> st, int val){
    if(!st.empty() && !st.top()){
        val = -val;
    }
    
    if(m.find(c) == m.end()){
        m[c] = val;
    }
    else{
        m[c] += val;
    }
}

int getVal(string a, int i){
    if(a[i] == '+'){
        return 1;
    }
    
    return -1;
}

void makeMap(map<char, int>& forA, string a){
    int i = 0, n = a.size();
    stack<bool> posA;
    
    while(i < n){
        if(a[i] == '+' || a[i] == '-'){
            if(a[i+1] == '('){
                posA.push(check(posA, a[i]));
            }
            else{
                // has to be a char
                insertInMap(forA, a[i+1], posA, getVal(a, i));
            }
            i++;
        }
        else{
            if(a[i] == ')'){
                posA.pop();
            }
            else if(a[i] == '('){
                posA.push(check(posA, '+'));    
            }
            else{
                insertInMap(forA, a[i], posA, 1);
            }
        }
        i++;
    }
}

string compare(map<char, int>& m1, map<char, int>& m2){
    string ans = "NO";
    
    if(m1.size() != m2.size()){
        return ans;
    }
    
    map<char, int> :: iterator it = m1.begin();
    
    while(it != m1.end()){
        char c = it->first;
        int val = it->second;
        
        if(m2.find(c) == m2.end()){
            return ans;
        }
        else if(m2[c] != val){
            return ans;
        }
        
        it++;
    }
    
    return "YES";
}

void printMap(map<char, int>& m){
    map<char, int> :: iterator it = m.begin();
    
    while(it != m.end()){
        cout << it->first << "->" << it->second << endl;    
        it++;
    }
}

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string a, b;
	    cin >> a >> b;
	    
	    map<char, int> forA, forB;
        
        makeMap(forA, a);
        makeMap(forB, b);
	    
	   // printMap(forA);
    //     printMap(forB);
	    
	    cout << compare(forA, forB) << endl;
	}
	
	return 0;
}
