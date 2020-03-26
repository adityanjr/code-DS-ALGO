// http://www.geeksforgeeks.org/write-a-program-to-add-two-numbers-in-base-14

#include <iostream>
#include <cstring>
using namespace std;

int toInt(char a){
	if('0'<= int(a) && int(a) <= '9')
		return int(a)-int('0');
	else
		return 10+int(a)-int('A');
}

char toChar(int x){
	if(x<10)
		return char(int('0')+x);
	return char(int('A')+x-10);
}

string sumBaseK(char* num1, char* num2, int k){
	int n1 = strlen(num1);
	int n2 = strlen(num2);
	int i =n1-1, j=n2-1;
	string res = "";
	int carry = 0;
	while(i>=0 && j>=0){
		int sum = toInt(num1[i]) + toInt(num2[j]) + carry;
		carry = sum/k;
		res = toChar(sum%k) + res;
		i--;	j--;
	}
	while(i >= 0){
		int sum = toInt(num1[i]) + carry;
		carry = sum/k;
		res = toChar(sum%k) + res;
		i--;
	}
	while(j >= 0){
		int sum = toInt(num1[j]) + carry;
		carry = sum/k;
		res = toChar(sum%k) + res;
		j--;
	}
	if(carry){
		res = '1' + res;
	}
	return res;
}

int main(){
	char *num1 = "DC2";
    char *num2 = "DDD";
 	string res = sumBaseK(num1, num2, 14);
    cout<<res;
	return 0;
}

