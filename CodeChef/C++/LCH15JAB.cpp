#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    const int N = 26;
    int t; std::cin >> t;
    while(t--){
        std::string s; std::cin >> s;
        std::vector<int> count(N, 0);
        for(int p = 0; p < s.size(); p++){++count[s[p] - 'a'];}
        sort(count.begin(), count.end());
        std::cout << ((2 * count[N - 1] == s.size()) ? "YES" : "NO") << std::endl;
    }

    return 0;
}
