#include <iostream>

int main(){

    int t; std::cin >> t;
    while(t--){
        std::string s; std::cin >> s;
        bool lucky(s[0] != s[1]);
        for(int p = 2; p < s.size(); p++){if(s[p] != s[p % 2]){lucky = 0; break;}}
        puts(lucky ? "YES" : "NO");
    }

    return 0;
}
