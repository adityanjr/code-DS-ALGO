/*
 *  This problem was asked by Twitter.

    You run an e-commerce website and want to record the last N order ids in a log. 
    Implement a data structure to accomplish this, with the following API:

    record(order_id): adds the order_id to the log
    get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or equal to N.
    You should be as efficient with time and space as possible.
 *
 */


/*
 * let me know if you got any better idea : offamitkumar@gmail.com
 */
#include<bits/stdc++.h>
using namespace std;
vector<int>Log;
void record(int order_id){
    Log.emplace_back(order_id);
}
int get_last(int i){
    assert((int)Log.size()>=i);
    return Log.at((int)Log.size()-(i-1)-1);
}
int main(void){
    int n; // number of order
    cin>>n;
    while(n--){
        int order_id; 
        cin>>order_id;
        record(order_id);
    }
    cout<<get_last(1)<<endl;
    cout<<get_last(2)<<endl;
    return 0;
}
