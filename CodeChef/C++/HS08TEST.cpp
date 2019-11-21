#include <iostream>
using namespace std;

int main(int argc, char* argv[]){

    size_t withdrawal;double currentBalance;

    cin >> withdrawal;
    cin >> currentBalance;
    
    const double fee = 0.5;
    double newBalance = currentBalance;

    if( (withdrawal % 5) == 0 && currentBalance > withdrawal + fee){newBalance = currentBalance - (withdrawal + fee);}
    cout << newBalance << endl;

    return 0;
}
