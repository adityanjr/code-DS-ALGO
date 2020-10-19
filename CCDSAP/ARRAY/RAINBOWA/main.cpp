//https://www.codechef.com/problems/RAINBOWA
#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    // enter the no of test cases
    cin>>T;
    while(T--){
        int arr[200] , n;
        // enter the no of inputs 
        cin>>n;
        //enter the array 
        for(int j = 1 ; j <= n ; j++) cin>>arr[j];
        //initialization
        int it1 = 1 , it2 = n , number = 0;
        bool sol = 1;
        //logic
        while(number < 6){
            ++number;
            if(arr[it1] != number || arr[it2] != number){
                sol = 0;
                break;
            }
            int r1 = 0 , r2 = 0;
            while(it1 <= n && arr[it1] == number) ++r1 , ++it1;
            while(it2 > 0 && arr[it2] == number) ++r2 , --it2;
            if(r1 != r2){
                sol = 0;
                break;
            }
        }

        if(number == 6 && it1 <= it2){
            ++number;
            for(int j = it1 ; j <= it2 ; j++)
                if(arr[j] != 7)
                    sol = 0;
        }
        else sol = 0;
        if(sol) puts("yes");
        else puts("no");
    }
}
// Time Complexity : O(n)
// Space COmplexity: O(1)
