#include<iostream>
using namespace std ;

void counting_sort(int a[] , int n){
    int freq[1000]={0}, i  ;
    for(i=0 ; i<n ;i++){
        freq[a[i]]++ ;
    }
    i=0 ;
    while(i<3) // use 3 instead of n 
        if(freq[i]==0)
            i++ ;
        else{
            while(freq[i]){ // loop over the freq of elements
            cout<< i << endl;
            freq[i]-- ;
            }
        }
}

int main(){
    int a[100000] = {0}, n , i ;
    cin >> n ;
    for(i=0 ; i< n ; i++ ){
        cin >> a[i] ;
    }
    counting_sort(a,n) ;
    return 0 ;
}