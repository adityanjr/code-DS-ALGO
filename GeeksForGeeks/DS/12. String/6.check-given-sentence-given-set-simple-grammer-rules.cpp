// http://www.geeksforgeeks.org/check-given-sentence-given-set-simple-grammer-rules

#include <bits/stdc++.h>
using namespace std;

bool isCap(char a){
	if(a >= 'A' && a <= 'Z')
		return true;
	return false;
}

bool isSmalll(char a){
	if(a >= 'a' && a <= 'z')
		return true;
	return false;
}

bool checkSentence(string str){
	int n = str.length();
	if(!isCap(str[0]))
		return false;
	bool space = false;
	bool cap = false;
	for(int i=1; i<n; i++){
		if(str[i] == ' '){
			if(space)
				return false;
			space = true;
			continue;
		}
		if(isCap(str[i])){
			if(cap){
				return false;
			}
			if(str[i] != ' ')
				return false;
			cap = true;
			continue;
		}
		if(str[i] == '.'){
			if(i == n-1)
				return true;
			return false;
		}
		cap = false;
		space = false;
	}
	return false;
}

int main(){
	char *str[] = { "I love cinema.", "The vertex is S.",
                    "I am single.", "My name is KG.",
                    "I lovE cinema.", "GeeksQuiz. is a quiz site.",
                    "I love Geeksquiz and Geeksforgeeks.",
                    "  You are my friend.", "I love cinema" };
    int str_size = sizeof(str) / sizeof(str[0]);
    int i = 0;
    for (i = 0; i < str_size; i++)
     checkSentence(str[i])? printf("\"%s\" is correct \n", str[i]):
                            printf("\"%s\" is incorrect \n", str[i]);
	return 0;
}

