// # Find Last Digit Of a^b for Large Numbers

// - You are given two integer numbers , the base a (number of digits d, such that 1 <= d <= 1000) 
//   and the index b (0 <= b <= 922*10^15). You have to find the last digit of a^b.

// - Examples:

// - Input  : 3 10
// - Output : 9

// - Input  : 6 2
// - Output : 6

// - Input  : 150 53
// - Output : 0

// Algorithm :

// - Since number are very large we store them as a string.
// - Take last digit in base a.
// - Now calculate b%4. Here b is very large so we follow this approach to calculate mod of large number.
// - If b%4==0 that means b is completely divisible by 4, so our exponent now 
//   will be exp = 4 because by multiplying number 4 times, we get the last digit according to cycle table in above diagram.
// - If b%4!=0 that means b is not completely divisible by 4, so our exponent now will be exp=b%4 because 
//   by multiplying number exponent times, we get the last digit according to cycle table in above diagram.
// - Now calculate ldigit = pow( last_digit_in_base, exp ).
// - Last digit of a^b will be ldigit%10.


#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <stack>
using namespace std;

int Modulo(int a, string b)
{
    // Initialize result
    int mod = 0;
 
    // calculating mod of b with a to make
    // b like 0 <= b < a
    for (int i=0; i<b.length(); i++)
        mod = (mod*10 + b[i] - '0')%a;
 
    return mod; // return modulo
}
 
// function to find last digit of a^b
int LastDigit(string a, string b)
{
    int len_a = a.length();
    int len_b = b.length();
 
    // if a and b both are 0
    if (len_a==1 && len_b==1 && b[0]=='0' && a[0]=='0')
        return 1;
 
    // if exponent is 0
    if (len_b==1 && b[0]=='0' )
        return 1;
 
    // if base is 0
    if (len_a==1 && a[0]=='0')
        return 0;
 
    // if exponent is divisible by 4 that means last
    // digit will be pow(a, 4) % 10.
    // if exponent is not divisible by 4 that means last
    // digit will be pow(a, b%4) % 10
    int exp = (Modulo(4,b)==0)? 4 : Modulo(4, b);
 
    // Find last digit in 'a' and compute its exponent
    int res = pow(a[len_a - 1] - '0', exp);
 
    // Return last digit of result
    return res % 10;
}

int main(){
	string a,b;
	while(cin>>a>>b){
		cout<<LastDigit(a,b)<<endl;
	}
}
