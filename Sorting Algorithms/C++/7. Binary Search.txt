#include<iostream>
using namespace std;

int binarySearch(long arr[], int low, int high, long long key){
  int result = -1;
  while (low<=high) {
    int mid= (low+high)/2;
    if(arr[mid]==key){
      result = mid;
      high = mid-1; 
    }
    else if (arr[mid]<key){
      low = mid+1;
    }
    else{
      high = mid-1;
    }
  }
  return result;
}

int main() {
  long arr[1000];
  long long n;
  cin>>n;
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  long long key;
  cin>>key;
  long result = binarySearch(arr, 0, n, key);
  cout<<result;
  return 0;
}