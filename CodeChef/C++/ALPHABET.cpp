#include <iostream>
#include <vector>

int main(){

    const int N = 26;
    std::string a; std::cin >> a;
    std::vector<bool> v(N, 0);
    for(int p = 0; p < a.size(); p++){v[a[p] - 'a'] = 1;}

    int t; std::cin >> t;
    while(t--){
        std::string u; std::cin >> u;
        bool possible(1);
        for(int p = 0; p < u.size(); p++){
            if(!v[u[p] - 'a']){possible = 0; break;}
        }
        puts(possible ? "Yes" : "No");
    }

    return 0;
}
