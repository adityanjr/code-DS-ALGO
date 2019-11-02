#include<iostream>
using namespace std;
int kadane(int arr[],int test){
  int ms=0,cs=0;

  for(int j=0;j<test;j++){
    cs=cs+arr[j];
    if(cs<0){
    cs=0;
    }
    ms=max(cs,ms);
  }
  return ms;
}

void maxCircularSum(int a[], int n){
  for(int j=0;j<n;j++){
    cin>>a[j];
  }
  int max_kadane = kadane(a, n);
  int max_wrap = 0, i;
  for (i=0; i<n; i++){
    max_wrap += a[i];
    a[i] = -a[i];
  }
  max_wrap = max_wrap + kadane(a, n);
  int y = (max_wrap > max_kadane)? max_wrap: max_kadane;
  cout<<y<<endl;
}

int main(){
  int n;
  cin>>n;
  int test[n];
  for(int i=0;i<n;i++){
    cin>>test[i];
    int arr[test[i]];
    maxCircularSum(arr,test[i]);
  }
  return 0;
}