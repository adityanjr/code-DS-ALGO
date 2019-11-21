#include <iostream>

int main(){

    int t; std::cin >> t;
    while(t--){
        long n; std::cin >> n;
        std::string s; std::cin >> s;
        long r(0), b(0), g(0);
        for(long p = 0; p < s.size(); p++){
            if(s[p] == 'R'){++r;}
            else if(s[p] == 'B'){++b;}
            else if(s[p] == 'G'){++g;}
        }

        long max = r;
        if(b > max){max = b;}
        if(g > max){max = g;}
        long ans = n - max;
        std::cout << ans << std::endl;
    }

    return 0;
}
