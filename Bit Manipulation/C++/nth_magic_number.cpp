//# MAGIC NUMBER
//A magic number is defined as a number which can be expressed as a power of 5 or sum of unique powers of 5. 
//First few magic numbers are 5, 25, 30(5 + 25), 125, 130(125 + 5), ….

#include <bits/stdc++.h> 
using namespace std; 
 
int nthMagicNo(int n) 
{ 
    int pow = 1, answer = 0; 

    
    while (n) 
    { 
    pow = pow*5; 

     
    if (n & 1) 
        answer += pow; 

    
    n >>= 1;
    } 
    return answer; 
} 

int main() 
{ 
    int n;
    cin>>n;
    cout << "nth magic number is " << nthMagicNo(n) << endl; 
    return 0; 
} 
