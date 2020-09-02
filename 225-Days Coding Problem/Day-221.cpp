/* This problem was asked by Zillow. 
 * Let's define a "sevenish" number to be one which is either a power of 7, 
 * or the sum of unique powers of 7. 
 * The first few sevenish numbers are 1, 7, 8, 49, and so on. 
 *
 * Create an algorithm to find the nth sevenish number.
 */

#include <bits/stdc++.h>
using namespace std;

long long nth_Sevenish_number(array<long long , 12>&power_of_7,const int &number){
    int mask = 1;
    long long ans{};
    for(int i=0;i<30;++i){
        if(number&mask){
            ans+=power_of_7.at(i);
        }
        mask<<=1;
    }
    return ans;
}

int main(void){
    array<long long , 12>power_of_7;
    for(int i=0;i<static_cast<int>(power_of_7.size());++i){
        if(i==0){
            power_of_7.at(i) = 1;
        }else{
            power_of_7.at(i) = power_of_7.at(i-1)*7;
        }
    }
    int number;
    cin>>number;
    cout<<nth_Sevenish_number(power_of_7,number)<<endl;
    return 0;
}
