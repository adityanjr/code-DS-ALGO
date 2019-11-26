#include <bits/stdc++.h>
using namespace std;

int lcm(int a,int b)
{
    int temp = a;
    while(temp%b!=0)
    {
        temp+=a;
    }
    return temp;
}

int main()
{
    cout<<lcm(3,9)<<endl;//Answer: 9
    cout<<lcm(24,36)<<endl;//Answer: 72
    cout<<lcm(12,80);//Answer: 240
    return 0;
}

//------------------------------------------------------------>

#include <iostream>
using namespace std;

//Euclidean gcd algorithm to compute gcd of two numbers in log(n) time complexity
int gcd(int a, int b)
{
    if(b == 0) 
    {
        return a;
    }
    return gcd(b, a%b);
}

//Using the mathematical property that lcm(a,b) = (a*b)/gcd(a,b)
int lcm(int a, int b)
{
    return (a*b)/gcd(a,b);
}

int main()
{
    int a,b;
    cin>>a>>b;

    cout<<lcm(a,b);
}