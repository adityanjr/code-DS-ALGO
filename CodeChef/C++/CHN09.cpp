#include <iostream>

int main(){

    std::ios_base::sync_with_stdio(false);
    int t; std::cin >> t;
    while(t--){
        std::string s; std::cin >> s;
        long countA(0), countB(0);
        for(size_t p = 0; p < s.size(); p++){
            countA += (s[p] == 'a');
            countB += (s[p] == 'b');
        }

        std::cout << ((countA < countB) ? countA : countB) << std::endl;
    }

    return 0;
}
