#include <iostream>

int64_t factorial(int a){
    int64_t res(1);
    for(int p = 1; p <= a; p++){res *= p;}
    return res;
}


int main(){

    int T; std::cin >> T;
    while(T--){
        int64_t x; std::cin >> x;
        std::cout << factorial(x) << std::endl;
    }

    return 0;
}
