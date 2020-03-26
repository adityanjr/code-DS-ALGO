// http://www.geeksforgeeks.org/divide-and-conquer-set-2-karatsuba-algorithm-for-fast-multiplication

#include <bits/stdc++.h>
using namespace std;

typedef long long int li;

int makeEqualLength(string &a, string &b){
	int aLen = a.length();
	int bLen = b.length();
	while(aLen < bLen){
		a = '0'+a;
		aLen++;
	}
	while(bLen < aLen){
		b = '0'+b;
		bLen++;
	}
	return aLen;
}

int multiplySingleBit(string a, string b){
	return (a[0]-'0')*(b[0]-'0');
}

string addBitStrings(string a, string b){
	int n = makeEqualLength(a, b);
	int carry = 0;
	string res = "";
	for(int i=n-1; i>=0; i--){
		int first = a.at(i)-'0';
		int second = b.at(i)-'0';
		int sum = (first^second^carry)+'0';
		res = (char)sum + res;
		carry = (first&second) | (second&carry) | (carry&first);
	}
	if(carry)
		res = '1' + res;
	return res;
}

li multiply(string a, string b){
	//cout<<"#"<<a<<" "<<b<<'\n';
	int n = makeEqualLength(a, b);
	if (n==0)
		return 0;
	if(n==1)
		return multiplySingleBit(a, b);
	int fl = n/2;
	int sh = n-fl;
	li p1 = multiply(a.substr(0, fl), b.substr(0, fl));
	li p2 = multiply(a.substr(fl), b.substr(fl));
	//cout<<"@"<<p1<<" "<<p2;
	li p3 = multiply(addBitStrings(a.substr(0, fl), a.substr(fl)), addBitStrings(b.substr(0, fl), b.substr(fl)));
	return p1*(1<<(2*sh)) + (p3-p1-p2)*(1<<sh) + p2;
}

int main(){
	printf ("%ld\n", multiply("1100", "1010"));
    printf ("%ld\n", multiply("110", "1010"));
    printf ("%ld\n", multiply("11", "1010"));
    printf ("%ld\n", multiply("1", "1010"));
    printf ("%ld\n", multiply("0", "1010"));
	printf ("%ld\n", multiply("111", "111"));
    printf ("%ld\n", multiply("11", "11"));
	return 0;
}

