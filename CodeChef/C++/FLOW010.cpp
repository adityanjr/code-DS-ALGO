#include <cstdio>
#include <iostream>

int main(){

    int t; std::cin >> t;
    while(t--){
        std::string s; std::cin >> s;
        if(s[0] == 'B' || s[0] == 'b'){puts("BattleShip");}
        else if(s[0] == 'C' || s[0] == 'c'){puts("Cruiser");}
        else if(s[0] == 'D' || s[0] == 'd'){puts("Destroyer");}
        else if(s[0] == 'F' || s[0] == 'f'){puts("Frigate");}
    }

    return 0;
}
