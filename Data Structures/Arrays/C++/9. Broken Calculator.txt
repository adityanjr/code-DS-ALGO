#include<iostream>
using namespace std;
int main() {
	int n, m=1, temp=0, x, i, j;
	cin>>n;
	int arr[1000000];
	arr[0]=1;

	for(i=1; i<=n; i++){
		for(j=0; j<m; j++){
			x=arr[j]*i+temp;
            arr[j]=x%10;
            temp=x/10;
		}
		while(temp>0){
			arr[m]=temp%10;
            temp=temp/10;
            m++;
		}
	}

	for(i=m-1; i>=0; i--){
		cout<<arr[i];
	}
	return 0;
}
