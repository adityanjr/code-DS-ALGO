#include <iostream>

int main(){

    std::ios_base::sync_with_stdio(false);
    long c(0), h(0), e(0), f(0);
    std::string s; std::cin >> s;
    for(size_t p = 0; p < s.size(); p++){
        if(s[p] == 'C'){++c;}
        else if(s[p] == 'H'){h += (h < c);}
        else if(s[p] == 'E'){e += (e < h);}
        else if(s[p] == 'F'){f += (f < e);}
    }

    std::cout << f << std::endl;

    return 0;
}
