// staircasesearch
#include<iostream>
using namespace std;

int main(){
	int n , m;
	cin>>n>>m;
	int arr[n][m];

	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<m ; j++)
		{
			cin>>arr[i][j];
		}
	}

	int key;
	cin>>key;

	int i=0 , j=m-1;

	while(i<n and j>=0)
	{
		if(arr[i][j] == key)
		{
			cout<<"element found: "<<i<<" "<<j<<endl;
			break;
		}
		else if(key > arr[i][j])
		{
			i++;
		}
		else
		{
			j--;
		}
	}

	if(i==n || j<0)
	{
		cout<<"element not found"<<endl;
	}

	return 0;
}