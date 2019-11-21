#include <iostream>
using namespace std;

int main(){

    size_t n,k; scanf("%zd %zd", &n, &k); 
    size_t currentInput, counter = 0;

    for(size_t m = 0; m < n ; m++){
        scanf("%zd", &currentInput);
        if(currentInput % k == 0){counter++;}
    }
    cout << counter << endl;

    return 0;
}
