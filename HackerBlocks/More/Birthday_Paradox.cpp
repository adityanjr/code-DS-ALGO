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

	int i,j,k,len,sum,count;
	string str;
	int t;
	double n;

	cin >> n;

	double num = 365;
	double den = 365;
	double p = 1;
	double people = 0;
	double limit = 1-n;

	while(p>limit){
		p*=num/den;
		num--;
		people++;
	}
	cout << people << endl;


	return 0;
}
