#include <iostream>
using namespace std;
int main() {
    int i=0;
    char a[50];
    cin>>a;
    if(a[i]=='9'){
        i++;
    }         
     //iterate over remaining
    while (a[i]!='\0'){
        int digit = a[i] - '0';  //convert char to int digit
        if(digit>=5){
            digit = 9-digit;
            a[i] = digit + '0';
        }
        i++;
    }
    cout<<a;
    return 0;
}
