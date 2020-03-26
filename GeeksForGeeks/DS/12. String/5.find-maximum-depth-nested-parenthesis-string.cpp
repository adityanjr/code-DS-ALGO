// http://www.geeksforgeeks.org/find-maximum-depth-nested-parenthesis-string

#include <bits/stdc++.h>
using namespace std;

typedef stack<char> sc;

int maxDepth(string str){
	sc s;
	int M = 0;
	for(int i=0; i<str.length(); i++){
		if(str[i] == '('){
			s.push('(');
		}
		else if(str[i] == ')'){
			if(M < s.size())
				M = s.size();
			if(s.empty())
				return -1;
			s.pop();
		}
	}
	if(s.empty())
		return M;
	return -1;
}

int main(){
	string s = "(b) ((c) ()";
    cout << maxDepth(s);
    return 0;
	return 0;
}