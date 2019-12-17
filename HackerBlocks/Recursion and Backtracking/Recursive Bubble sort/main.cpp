#include <iostream>
using namespace std;
void bubblesort(int arr[], int j,int n){
    if(n==1)
        return;
    if(j==n-1)
        return bubblesort(arr,0,n-1);
    if(arr[j]>arr[j+1])
       swap(arr[j],arr[j+1]);

    return bubblesort(arr,j+1,n);

}
int main()
{
    int arr[]= {23,42,234,22,245,2564,65,516};
    bubblesort(arr,0,8);
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
