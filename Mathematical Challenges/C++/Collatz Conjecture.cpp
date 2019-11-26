// # Collatz Conjecture #
// In the field of mathematics the collatz conjecture was posed by L. Collatz in 1937 which states that given a number n, one can  always
// 'get to one' by applying the following function recursively on the number.

// ## Function for Collatz Conjecture ##

// 1. **If number is even ** :
//     number = number / 2

// 2. **If number is odd ** :
//     number = (3 * number) + 1


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <iomanip>

using namespace std;

typedef unsigned long long int ulli;

vector<ulli> collatz(ulli number){

        vector<ulli> seq;

        while(number > 1){

                if( number%2 == 1 ){
                      number = (3*number) + 1;
                      seq.push_back(number);
                }
                else{
                      number = number/2;
                      seq.push_back(number);
                }

        }

        return seq;
}


void printsequence(vector<ulli> &seq){

      for(int i = 0;i < seq.size();i++){
            cout<<seq[i]<<" ";
      }
      cout<<endl;

}
int main(){

        ios_base::sync_with_stdio(false);

        ulli number;
        cout<<"Enter the number for which collatz sequence is to be displayed : ";
        cin>>number;

        vector<ulli> sequence;
        sequence = collatz(number);

        printsequence(sequence);

        return 0;
}
