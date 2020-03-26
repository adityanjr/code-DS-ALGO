#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	#endif

	int i,j,k,len,n,sum,count;
	string str;

	cin >> str;

	i=0;

	if(str[i]=='9'){
		i++;
	}

	for(;i<str.length();i++){
		int digit = str[i]-'0';
		if(digit>=5){
			digit=9-digit;
			str[i]=digit+'0';
		}
	}
	cout << str << endl;

	return 0;
}
