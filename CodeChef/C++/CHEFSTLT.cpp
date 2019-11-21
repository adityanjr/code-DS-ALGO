#include <iostream>

int main(){

    int t; std::cin >> t;
    while(t--){
        std::string s1, s2; std::cin >> s1 >> s2;
        int min(0), max(0);
        for(int p = 0; p < s1.size(); p++){
            if(s1[p] != '?' && s2[p] != '?'){
                min += (s1[p] != s2[p]);
                max += (s1[p] != s2[p]);
            }
            else{++max;}
        }

        std::cout << min << " " << max << std::endl;
    }

    return 0;
}
