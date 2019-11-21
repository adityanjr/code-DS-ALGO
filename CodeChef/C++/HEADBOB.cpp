#include <cstdio>
#include <iostream>

int main(){

    std::ios_base::sync_with_stdio(false);
    int T; std::cin >> T;
    while(T--){
        int len; std::string s; std::cin >> len >> s;
        bool y(0), n(0), i(0);
        for(int p = 0; p < s.size(); p++){
            if(s[p] == 'Y'){y = 1;}
            else if(s[p] == 'N'){n = 1;}
            else if(s[p] == 'I'){i = 1;}
        }

        if(i){puts("INDIAN");}
        else if(y){puts("NOT INDIAN");}
        else{puts("NOT SURE");}
    }

    return 0;
}
