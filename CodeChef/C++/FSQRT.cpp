#include <iostream>
#include <cmath>

int main(){

    int T; std::cin >> T;
    while(T--){
        long x; std::cin >> x;
        long r = sqrt(x);
        std::cout << r << std::endl;
    }

    return 0;
}
