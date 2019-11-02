#include<iostream>
using namespace std;
void ans(int *a,int *b,int *c,int n,int m){
    int sum = 0,carry = 0;
    int k = max(n,m);
    for(int i=0;i<k;i++){
        sum = a[i]+b[i]+carry;
        c[i] = sum%10;
        carry = sum/10;
    }
    int i=k-1;
    if(carry){
        c[k]=carry;
        i=k;
    }
    for(;i>=0;i--){
        cout<<c[i]<<", ";
    }
    cout<<"END";
}

int main(){
    int n,m;
    cin>>n;
    int a[100] = {0};
    int b[100] = {0};
    for(int i=n-1;i>=0;i--){
        cin>>a[i];
    }
    cin>>m;
    for(int i=m-1;i>=0;i--){
        cin>>b[i];
    }

    int c[100] = {0};
    ans(a,b,c,n,m);
    return 0;
  }