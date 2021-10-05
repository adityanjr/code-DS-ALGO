#include <iostream>
using namespace std;

int divisors(int n){
    int count=0;
    int num = n;
    while(n>0){
        int digit = n%10;
        if(digit!=0 && num%digit==0){
            count++;
        }
        n=n/10;
    }
    return count;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<divisors(n)<<endl;
    }
}