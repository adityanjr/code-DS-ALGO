//https://leetcode.com/problems/trapping-rain-water/
//time complexity 0(n)

//FAANG INTERVIEW question Rain Water Trapping problem 


#include<iostream>
using namespace std;
int rainWaterHarwest(int arr[],int n){
int ans=0;        //to calculate final answer
int left_max=0;   // Which stores the current max height of the left side 
int right_max=0;  //Which stores the current max height of the right side
int left=0;       //left pointer
int right=n-1;    //right pointer

    //when they cross each other loop break
    while(left<right){
        if(arr[left] < arr[right]){
            if(arr[left]>left_max){
                left_max=arr[left]; //update max height of left tower
            }else{
                ans +=left_max- arr[left];//adding water with previous stored water
            }
            left++;
        }
        else{
            if(arr[right]>right_max){  
                right_max=arr[right];  //update right max
            }
            else{
                ans +=right_max -arr[right];
            }
            right--;
        }
    }
    return ans;
}


int main(){
     int n;
     cout<<"Enter no of element in array\n";
     cin>>n;
     int arr[1000];

     cout<<"Enter height of tower\n";
     for(int i=0;i<n;i++){
         cin>>arr[i];
     }
     cout<<"Stored water: \n";
     cout<<rainWaterHarwest(arr,n);
}