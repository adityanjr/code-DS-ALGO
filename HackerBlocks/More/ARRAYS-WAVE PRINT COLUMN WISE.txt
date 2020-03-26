#include<iostream>
using namespace std;
void input(int arr[][10],int p,int q)
{
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++)
        cin>>arr[i][j];
    }
}
int main() {
    int m,n,arr[10][10];
    cin>>m>>n;
    input(arr,m,n);
    int i,j;
    for(j=0;j<n;j++)
    {
        if(j%2==0)
        {
            for(i=0;i<m;i++)
            cout<<arr[i][j]<<", ";
        }
        else
        {
            for(i=m-1;i>=0;i--)
            cout<<arr[i][j]<<", ";
        }
    }
    cout<<"END"<<endl;
	return 0;
}