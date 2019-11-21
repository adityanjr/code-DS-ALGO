#include <iostream>
#include <vector>

int main(){

    std::ios_base::sync_with_stdio(false);
    int t; std::cin >> t;
    while(t--){
        int n, m; std::cin >> n >> m;
        std::vector<int> count(m, 0);
        while(n--){
            std::string s; std::cin >> s;
            for(int p = 0; p < m; p++){count[p] += (s[p] == '1');}
        }

        long total(0);
        for(int p = 0; p < m; p++){total += count[p] * (count[p] - 1) / 2;}
        std::cout << total << std::endl;
    }

    return 0;
}
