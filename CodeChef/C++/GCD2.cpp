#include<iostream>

long gcd (long a, long b){return (b == 0) ? a : gcd (b, a%b);}

int main(){

    int t(0); scanf("%d\n", &t);
    while(t--){
        long a; std::string b; std::cin >> a >> b;
        if(a == 0){std::cout << b << std::endl; continue;}

        long c(0);
        for(int p = 0; p < b.size(); p++){
            c = 10 * c + (b[p] - '0');
            c %= a;
        }
        
        std::cout << gcd(a, c) << std::endl;
    }
    return 0;
}
