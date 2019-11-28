#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		string s;
		cin >> s;

		string str1 = "010";
		string str2 = "101";

		std::size_t found1 = s.find(str1);
		std::size_t found2 = s.find(str2);

		if ((found1!=std::string::npos)||(found2!=std::string::npos))
    		printf("Good\n");
    	else 
    		printf("Bad\n");

	}	

	return 0;
}