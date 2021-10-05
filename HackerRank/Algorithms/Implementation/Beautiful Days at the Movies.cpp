#include <iostream>
using namespace std;

int reverse(int n){
    int rev=0;
    while(n>0){
        int rem = n%10;
        rev = rev*10 + rem;
        n /= 10;
    }
    return rev;
}
int main(){
    int start, end, k;
    cin>>start>>end>>k;

    int count = 0;
    for(int i= start; i<=end; i++){
        if(abs(i-reverse(i))%k ==0){
            count++;
        }
    }
    cout<<count;
    return 0;
}