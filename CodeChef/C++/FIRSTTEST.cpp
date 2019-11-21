#include <iostream>
using namespace std;

int main( int argc , char *argv[] ){

    int inputNumber = 0;
    const int answer = 42;

    while(true){
        cin  >> inputNumber;
        if(inputNumber == answer){break;}
        cout << inputNumber << endl;
    }
    return 0;
}
