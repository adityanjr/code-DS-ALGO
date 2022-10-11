#include<iostream>
using namespace std;

int temp[100];

void combine(int *a,int low,int mid,int high){
    int i=low;
    int j=mid+1;
    int k = low;

    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            temp[k++] = a[i];
            i++;
        }
        else{
            temp[k++] = a[j];
            j++;
        }
    }
    while(i<=mid){
        temp[k++] = a[i++];
    }

    while(j<=high){
        temp[k++]= a[j++];
    }

    //Copy the elements into original array
    for(i=low;i<=high;i++){
        a[i] = temp[i];
    }
}

void mergeSort(int *a,int low,int high){

    if(low<high){
        int mid= (low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        combine(a,low,mid,high);
     }
}

void print(int a[],int n){
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
    }
}

int main(){
    int a[]={5,6,1,2,3};
    int n = sizeof(a)/sizeof(n);
    mergeSort(a,0,n-1);
    print(a,n);
    return 0;
}
