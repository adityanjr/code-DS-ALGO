#include <cstdio>
#include <iostream>

int main(){

    int T; scanf("%d\n", &T);
    while(T--){
        std::string s1, s2; std::cin >> s1 >> s2;
        bool match(1);
        for(int p = 0; p < s1.size(); p++){
            if(s1[p] == '?' || s2[p] == '?' || s1[p] == s2[p]){continue;}
            match = 0; break;
        }
        puts(match ? "Yes" : "No");
    }

    return 0;
}
