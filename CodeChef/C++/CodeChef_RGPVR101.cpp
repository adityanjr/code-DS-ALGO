#include <bits/stdc++.h>
using namespace std;

int main(){

	int t;
	scanf("%d",&t);
	while(t--) {
		string myString, invString;
		cin >> myString;

		for(int i = (myString.size()/2) - 1; i >= 0 ; i --)
			invString[(myString.size()/2) - i - 1] = myString[i];

		cout << invString << endl;
	}

	return 0;
}