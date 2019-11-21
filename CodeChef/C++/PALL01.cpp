#include <iostream>

int main(){

    int t; std::cin >> t;
    while(t--){
        std::string s; std::cin >> s;
        bool pal(true);
        for(int p = 0; p < s.size() / 2; p++){
            if(s[p] != s[s.size() - 1 - p]){pal = 0; break;}
        }
        std::cout << (pal ? "wins" : "losses") << std::endl;
    }

    return 0;
}
