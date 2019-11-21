#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    size_t inputNumber, factor, output;
    int N; cin >> N;

    for(size_t k = 0; k < N ; k++){
        cin >> inputNumber;
        factor = 5, output = 0;
        while(factor <= inputNumber){
            output += inputNumber / factor;
            factor *= 5;
        }
        cout << output << endl;
    }
    return 0;
}
