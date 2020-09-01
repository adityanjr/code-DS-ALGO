/*
 * This problem was asked by Jane Street.  
 * cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair. 
 *
 * For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.  
 * Given this implementation of cons: 
     def cons(a, b):
         def pair(f):
             return f(a, b)
         return pair
 *  Implement car and cdr.
 *
 */

/*
 * I have no idea how to solve this one with given function 
 * so i implemented a c++ function 
 *
 * if you know solution then please share your approach : offamitkumar@gmail.com
 */


#include <bits/stdc++.h>
using namespace std;
pair<int,int>cons(int a, int b){
    return make_pair(a,b);
}
int car(pair<int,int>p){
    return p.first;
}
int cdr(pair<int,int>p){
    return p.second;
}
int main(void){
    cout<<car(cons(3,4))<<endl;
    cout<<cdr(cons(3,4))<<endl;
}
