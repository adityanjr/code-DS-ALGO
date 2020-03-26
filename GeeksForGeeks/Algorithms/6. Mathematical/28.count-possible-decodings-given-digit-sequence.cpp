// http://www.geeksforgeeks.org/count-possible-decodings-given-digit-sequence

#include <iostream>
#include <cstring>
using namespace std;

int countDecoding(char *digits, int n){
	if(n <= 1){
		return 1;
	}
	int res = 0;
	res += countDecoding(digits+1, n-1);
	if(n>1){
		if(digits[0] == '1'){
			return res + countDecoding(digits+2, n-2);
		}
		else if(digits[0] == '2' && int(digits[1]) <= int('6')){
			return res + countDecoding(digits+2, n-2);
		}
	}
}

int main(){
	char digits[] = "1234";
    int n = strlen(digits);
    cout<<"@";
    cout << "Count is " << countDecoding(digits, n);
    cout<<"@";
	return 0;
}

