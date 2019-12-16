#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin>>n;
int	total_size = 2 * n;
	int arr[n],arr1[n];
	vector<int>v;
	for(int i=0;i<n;i++){
        cin>>arr[i];
	}
	for(int i=0;i<n;i++){
        cin>>arr1[i];
	}
	for(int i=0;i<n;i++){
        v.push_back(arr[i]);
        v.push_back(arr1[i]);
	}
	sort(v.begin(),v.end());
	int median = (v.at(n-1)+v.at(n))/2;
    cout<<median<<endl;
}